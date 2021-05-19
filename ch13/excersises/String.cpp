
#include "String.h"
#include <cstring>
#include <iostream>

String::String(const char *cp) {
  std::cout << "Default constructor called!\n";
  auto newsize = strlen(cp);
  auto data = alloc.allocate(newsize);
  auto elem = cp[0];
  auto dest = data;
  for (auto i = 0; i != newsize; ++i) {
    alloc.construct(dest++, std::move(*cp++));
  }
  first_character = data;
  last_character = dest;
  cap = first_character + newsize;
}

String::String(const String &s) {
  std::cout << "Copy constructor called!\n";
  auto data = allocate_n_chars(s.begin(), s.end());
  first_character = data.first;
  last_character = cap = data.second;
}

String &String::operator=(const String &s) {
  std::cout << "Copy-assign constructor called!\n";
  auto data = allocate_n_chars(s.begin(), s.end());
  free();
  first_character = data.first;
  last_character = cap = data.second;

  return *this;
}

String::~String() { free(); }

std::pair<char *, char *> String::allocate_n_chars(const char *b,
                                                   const char *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

String::String(String &&s) noexcept
    : first_character(s.first_character), last_character(s.last_character),
      cap(s.cap) {
  std::cout << "Move constructor called!\n";
  s.first_character = s.last_character = s.cap = nullptr;
}

String &String::operator=(String &&s) noexcept {
  if (this != &s) {
    std::cout << "Move-assign constructor called!\n";
    free();
    first_character = s.first_character;
    last_character = s.last_character;
    cap = s.cap;
  }
  return *this;
}
