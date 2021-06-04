#include <iostream>
class Base {
public:
  virtual int fcn();
};
class D1 : public Base {
public:
  using Base::fcn; // add Base's fcn to scope
  int fcn(int) {   // override the version of it
    std::cout << "d1fcn";
    return 5;
  }                  // does not override fcn()
  virtual void f2(); //
};

class D2 : public D1 {
public:
  int fcn(int); // has its own fcn *is going to hide fcn(int)*
  int fcn();    // overrides Base's fcn()
  void f2();    // overrides D1's f2
};

int main() {
  D1 d1obj;
  D1 *p2 = &d1obj;
  p2->fcn(3);
}
