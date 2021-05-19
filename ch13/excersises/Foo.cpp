
#include <algorithm>
#include <iostream>
#include <vector>
class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;
  using Comp = bool(const int &, const int &);
  Foo sorted(Comp *);
  Foo sorted(Comp *) const;

private:
  std::vector<int> data;
};

Foo Foo::sorted() && {
  std::sort(data.begin(), data.end());
  std::cout << "rvalue sort!\n";
  return *this;
}

/* Foo Foo::sorted() const & { */
/*   Foo ret(*this); */
/*   std::sort(ret.data.begin(), ret.data.end()); */
/*   return ret; */
/* } */

Foo Foo::sorted() const & {
  Foo ret(*this); // makes copy of object, but since there are no
                  // overloads taking lvalues - will return error
                  // but only if used on variables that can be lvalues
  return ret.sorted();
}

/* Foo Foo::sorted() const & { */
/*   return Foo(*this).sorted(); */
/* } // calls the rvalue ref taking version */

int main(int argc, const char **argv) {
  Foo f;
  f.sorted();
  /* Foo f = Foo().sorted(); */
  return 0;
}
