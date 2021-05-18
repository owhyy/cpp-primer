
#include "String.h"
#include <cstring>
#include <iostream>
String::String(const char *cp) {

  auto newsize = strlen(cp);
  auto data = alloc.allocate(newsize);
  auto elem = first_character;
  auto dest = last_character;
  for (auto i = 0; i != newsize; ++i) {
    alloc.construct(dest++, cp);
  }
  free();
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

void String::reallocate() {
  auto newsize = (size() ? 2 * size() : 1);
  auto data = alloc.allocate(newsize);
  auto elem = first_character;
  auto dest = last_character;
  for (auto i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();

  first_character = data;
  last_character = dest;
  cap = first_character + newsize;
}

std::pair<char *, char *> String::allocate_n_chars(char *b, char *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}
