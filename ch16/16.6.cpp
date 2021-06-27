#include <iostream>
#include <iterator>
template <typename T, unsigned size> T *beg(T (&arr)[size]) { return arr; }
template <typename T, unsigned size> T *end(T (&arr)[size]) {
  return arr + size - 1;
}

int main() {

  int iarr[7] = {3, 2, 3, 4, 5, 919, 39};
  auto qq = beg(iarr);
  auto ee = end(iarr);
  std::cout << *qq << '\n';
  std::cout << *ee;
}
