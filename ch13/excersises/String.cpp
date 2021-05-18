
#include "String.h"
#include <cstring>
#include <iostream>

String::String(const char *cp) {
  auto newsize = strlen(cp);
  auto data = alloc.allocate(newsize);
  auto elem = cp[0];
  auto dest = data;
  for (auto i = 0; i != newsize; ++i) {
    alloc.construct(dest++, *cp++);
  }
  first_character = data;
  last_character = dest;
  cap = first_character + newsize;
}

String::String(const String &s) {
  auto data = allocate_n_chars(s.begin(), s.end());
  first_character = data.first;
  last_character = cap = data.second;
}

String &String::operator=(const String &s) {
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
