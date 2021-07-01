#include <iostream>
#include <string>

template <typename T> class Screen {
public:
  friend std::istream &operator>>(std::istream &is, Screen<T> &);
  friend std::ostream &operator<<(std::ostream &os, const Screen &);
  Screen(const char &s, T h, T w) : symbol(s), height(h), width(w) {
    cont = (std::string(h * w, s));
  };
  char get() { return cont[cursor_pos]; }
  Screen &move(std::string::size_type p1, std::string::size_type p2) {
    std::string::size_type row = p1 * width;
    cursor_pos = row + p2;
    return this;
  }

private:
  char symbol;
  std::string cont;
  std::string::size_type cursor_pos = 0;
  T height;
  T width;
};
