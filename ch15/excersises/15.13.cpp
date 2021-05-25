#include <iostream>
#include <string>
class base {
public:
  std::string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }

private:
  std::string basename;
};

class derived : public base {
public:
  void print(std::ostream &os) override {
    base::print(os);
    os << " " << i;
  }

private:
  int i;
};

int main() {
  base bobj;
  derived dobj;

  base *bp1 = &bobj;
  base &br1 = bobj;
  base *bp2 = &dobj;
  base &br2 = dobj;

  bobj.print(); // compile time
  dobj.print(); // compile time
  bp1->name();  // not virtual -> compile time
  bp2->name();  // not virtual -> compile time
  br1.print();  // run-time
  br2.print();  // run-time
}
