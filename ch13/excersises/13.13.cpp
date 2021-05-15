
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct X {

  X() { std::cout << " X()\n"; }
  X(const std::string &n) : name(n) { std::cout << name << " X()\n"; }
  X(const X &) { std::cout << name << " X(const X&)\n"; }
  /* X &operator=(const X &x) { */
  /*   std::cout << x.name << " X& operator=(const X&) " << name << ' \n'; */
  /*   return *this; */
  /* } */
  ~X() { std::cout << name << " ~X()\n"; }
  X operator=(const X &x) // non-reference taking does not print the name, as
  // it uses a copy ?
  {
    std::cout << x.name << " operator=(X x) " << name << '\n';
    return *this;
  }

private:
  int n;
  std::string name = "No Name";
};
struct int_class {

  ~int_class() { std::cout << "n destroyed\n"; }
  int n = 5;
};
int main() {
  std::vector<X> xv;
  /* xv.push_back(X("Pushed back")); */
  /* xv.push_back(X("Pushed back")); */
  xv.emplace(xv.end(), X("Emplaced"));
  xv.emplace(xv.end(), X("Emplaced"));
  /* auto sm_x = std::make_shared<X>("Smart Pointer"); */
  /* X *xp = new X("X Pointer"); */
  /* X obj_x("Ana"); */
  /* obj_x = X("Maria"); // copy constructor gets called here, but it is not
   * used, */
  // so it is destroyed
  /* X("Ana"); */
  /* X obj_x_2("Maria"); */
  /* X("ana") = X("johs"); */
  /* obj_x = obj_x_2; */
}
