#include "16.14.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const Screen<T> &scr) {
  for (T i = 0; i != scr.height; ++i) {
    for (T j = 0; j != scr.width; ++j) {
      os << scr.symbol;
    }
    os << '\n';
  }
  return os;
}
template <typename T>
std::istream &operator>>(std::istream &is, Screen<T> &scr) {
  std::cout << "Enter the symbol: ";
  is >> scr.symbol;

  std::cout << "Enter dimentions: ";
  is >> scr.height >> scr.width;

  scr.cont = std::string(scr.height * scr.width, scr.symbol);

  return is;
}
