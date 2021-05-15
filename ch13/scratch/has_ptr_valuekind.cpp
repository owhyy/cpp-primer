#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() { delete ps; }
  friend std::ostream &operator<<(std::ostream &stream, const HasPtr &p) {
    stream << *(p.ps) << ' ' << p.i << '\n';
    return stream;
  }

private:
  std::string *ps;
  int i;
};
HasPtr::HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

HasPtr &HasPtr::operator=(const HasPtr &orig) {

  ps = new std::string(*orig.ps);
  i = orig.i;
  return *this;
}

int main() {

  HasPtr p1("P1");
  HasPtr p2("P2");
  HasPtr p3(p1);
  HasPtr p4;
  p4 = p2;
  /* p4.ps = new std::string("Ana"); */
}
