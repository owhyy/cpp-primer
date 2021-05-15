#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  HasPtr(const HasPtr &);
  HasPtr &operator=(const HasPtr &);
  friend std::ostream &operator<<(std::ostream &stream, const HasPtr &p) {
    stream << *(p.ps) << ' ' << p.i << '\n';
    return stream;
  }
  ~HasPtr();

private:
  int i;
  std::string *ps;
  std::size_t *use;
};

HasPtr::HasPtr(const HasPtr &orig) : ps(orig.ps), i(orig.i), use(orig.use) {
  ++*use;
}

HasPtr &HasPtr::operator=(const HasPtr &orig) {

  ++*orig.use;     // increment right hand
  if (--*use == 0) // check if rcount > 1
  {
    delete ps;
    delete use;
  }
  ps = orig.ps;
  i = orig.i;
  use = orig.use;
  return *this;
}

HasPtr::~HasPtr() {
  if (--*use == 0) {
    delete use;
    delete ps;
  }
}

/* void f(HasPtr& p1, HasPtr &p2){ */
/*   p1.ps */
/* } */

int main() {

  HasPtr p1("P1");
  HasPtr p2("P2");
  HasPtr p3(p1);
  HasPtr p4;
  p4 = p2;
  std::cout << p4;
}
