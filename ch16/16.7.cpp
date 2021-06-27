#include <iostream>
template <typename T, unsigned sz> constexpr unsigned size(const T (&arr)[sz]) {
  return sz;
}

int main() {
  int iarr[3] = {3, 4, 5};
  std::cout << size(iarr);
}
