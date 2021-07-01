#ifndef __STRVEC_H
#define __STRVEC_H

#include <algorithm>
#include <memory>
#include <string>
#include <utility>

template <typename T> class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<T> il);
  StrVec(const StrVec &);
  StrVec &operator=(std::initializer_list<T> il);
  StrVec &operator=(const StrVec &);

  ~StrVec();
  void push_back(const T &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  T *begin() const { return elements; }
  T *end() const { return first_free; }

private:
  std::allocator<T> alloc;
  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  std::pair<T *, T *> alloc_n_copy(const T *, const T *);
  void free();
  void reallocate();

  T *elements;
  T *first_free;
  T *cap;
};

template <typename T> void StrVec<T>::free() {
  if (elements) {
    std::for_each(elements, first_free, [this](T &p) { alloc.destroy(&p); });
    alloc.deallocate(elements, cap - elements);
  }
}

template <typename T> StrVec<T>::~StrVec() { free(); }

template <typename T> void StrVec<T>::push_back(const T &t) {
  chk_n_alloc();
  alloc.construct(first_free++, t);
}

template <typename T>
std::pair<T *, T *> StrVec<T>::alloc_n_copy(const T *b, const T *e) {
  auto data = alloc.allocate(e - b);

  return {data, uninitialized_copy(b, e, data)};
}

template <typename T> StrVec<T>::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template <typename T> StrVec<T> &StrVec<T>::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

template <typename T> void StrVec<T>::reallocate() {

  auto sz = (size() ? 2 * size() : 1); // allocate 2x the size
  auto first = alloc.allocate(sz);
  auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                      std::make_move_iterator(end()), first);
  free(); // delete old data

  // initialize new data
  elements = first;
  first_free = last;
  cap = elements + sz;
}

#endif //__STRVEC_H
