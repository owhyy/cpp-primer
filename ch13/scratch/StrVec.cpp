#include "StrVec.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <new>
#include <utility>
StrVec::StrVec(std::initializer_list<std::string> il)
    : elements(nullptr), last_element(nullptr), cap(nullptr) {
  for (auto i : il)
    push_back(i);
}

/* void StrVec::free() { */
/*   if (elements) { */
/*     for (auto p = last_element; p != elements;) */
/*       alloc.destroy(--p); */
/*     alloc.deallocate(elements, cap - elements); */
/*   } */
/* } */

void StrVec::free() {
  if (elements) {
    auto p = last_element;
    std::for_each(elements, last_element,
                  [this](std::string &p) { alloc.destroy(&p); });
    alloc.deallocate(elements, cap - elements);
  }
}

std::pair<std::string *, std::string *>
StrVec::allocate_n_copy(const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec &s) {
  auto data = allocate_n_copy(s.begin(), s.end());
  elements = data.first;
  cap = last_element = data.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = allocate_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  cap = last_element = data.second;

  return *this;
}

void StrVec::reallocate() {
  auto sz = (size() ? 2 * size() : 1); // allocate 2x the size
  auto data = alloc.allocate(sz);      // where the allocation happens
  auto dest = data;                    // where to construct
  auto elem = elements;                // first member
  for (auto i = 0; i != size(); ++i) {
    alloc.construct(
        dest++,
        std::move(*elem++)); // move each member into new destination (data)
  }
  free(); // delete old data

  // initialize new data
  elements = data;
  last_element = dest;
  cap = elements + sz;
}

void StrVec::resize(int n) {
  auto sz = n;
  auto data = alloc.allocate(sz);
  auto dest = data;
  auto elem = elements;
  if (n < size()) {
    for (auto i = 0; i != n; ++i)
      alloc.construct(dest++, std::move(*elem++));

  } else {
    for (auto i = 0; i != size(); ++i)
      alloc.construct(dest++, std::move(*elem++));
    for (auto i = size(); i != n; ++i)
      alloc.construct(dest++, std::string());
  }
  free();
  elements = data;
  last_element = dest;
  cap = elements + sz;
}

void StrVec::resize(int n, const std::string &s) {
  auto sz = n;
  auto data = alloc.allocate(sz);
  auto dest = data;
  auto elem = elements;
  if (n < size()) {
    for (auto i = 0; i != n; ++i)
      alloc.construct(dest++, std::move(*elem++));

  } else {
    for (auto i = 0; i != size(); ++i)
      alloc.construct(dest++, std::move(*elem++));
    for (auto i = size(); i != n; ++i)
      alloc.construct(dest++, s);
  }
  free();
  elements = data;
  last_element = dest;
  cap = elements + sz;
}

void StrVec::reserve(int n) {
  if (n > size()) {
    auto sz = n;
    auto data = alloc.allocate(sz);
    auto dest = data;
    auto elem = elements;
    for (auto i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = data;
    last_element = dest;
    cap = elements + sz;

  } else
    return;
}
