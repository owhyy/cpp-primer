
#include <ctime>
#include <iostream>
#include <random>
#include <string>

struct numbered {
  numbered();
  numbered(const numbered &);
  numbered &operator=(const numbered &);
  int mysn;
};
numbered::numbered() {
  srand(time(NULL));
  mysn = rand() % 1000;
}

numbered::numbered(const numbered &orig) {
  /* srand(time(NULL)); */
  /* mysn = rand() % 1000; */
  mysn = rand() % 100;
}
numbered &numbered::operator=(const numbered &) {
  srand(time(NULL));
  mysn = rand() % 10;
  return *this;
}
void f(const numbered &s) { std::cout << s.mysn << '\n'; }

int main() {

  numbered a, b = a, c = b;
  f(a);
  f(b);
  f(c);
}
