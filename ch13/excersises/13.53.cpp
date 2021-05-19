#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std::chrono;
class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);     // copy constr
  HasPtr(HasPtr &&) noexcept; // move constr
  HasPtr &operator=(HasPtr &&) noexcept;
  /* HasPtr &operator=(const HasPtr &orig); */
  HasPtr &operator=(HasPtr);

  ~HasPtr() { delete ps; }

  void print() { std::cout << *ps << '\n'; }

  friend void swap(HasPtr &, HasPtr &);
  friend std::ostream &operator<<(std::ostream &stream, const HasPtr &p) {
    stream << *(p.ps) << ' ' << p.i << '\n';
    return stream;
  }
  bool operator<(HasPtr &rhs) { return *ps < *rhs.ps; }

private:
  std::string *ps;
  int i;
};
HasPtr::HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {
  std::cout << "Copy constructor called!\n";
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  /* std::cout << "Swapping " << *lhs.ps << " to " << *rhs.ps << '\n'; */
  using std::swap;
  swap(lhs.ps,
       rhs.ps); // swaps the pointers, doesn't create and allocate a new object
  swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
  std::cout << "Move constructor called!\n";
  p.i = 0;
  p.ps = 0;
}

HasPtr &HasPtr::operator=(HasPtr rhs) // slow, 6-9 ms on 12 calls
{
  std::cout << "Combined swapping constructor called!\n";
  swap(*this, rhs);
  return *this;
}

HasPtr &
HasPtr::operator=(HasPtr &&rhs) noexcept // not that fast (6ms on 12 calls ) but
                                         // still faster than combining both

{
  std::cout << "Move-assign noswap constructor called!\n";
  ps = rhs.ps;
  i = rhs.i;

  rhs.ps = 0;
  rhs.i = 0;

  return *this;
}

/* HasPtr &HasPtr::operator=(const HasPtr &orig) // very fast (0 ms on 40 */
/*                                               // copies) */
/* { */

/*   ps = new std::string(*orig.ps); */
/*   i = orig.i; */
/*   return *this; */
/* } */

int main() {
  std::vector<HasPtr> hptr_v;

  auto t0 = high_resolution_clock::now();

  HasPtr p1("test 1");
  HasPtr p2("test 2");
  HasPtr p3("test 3");
  HasPtr p4("test 4");
  HasPtr p5("test 5");
  HasPtr p6("test 1");
  HasPtr p7("test 2");
  HasPtr p8("test 3");
  HasPtr p9("test 4");
  HasPtr p10("test 5");

  /* p1 = p2; */
  /* p2 = p3; */
  /* p4 = p4; */
  /* p4 = p5; */

  /* p1 = p2; */
  /* p2 = p3; */
  /* p3 = p4; */
  /* p4 = p5; */

  /* p5 = p6; */
  /* p2 = p7; */
  /* p3 = p8; */
  /* p4 = p9; */

  /* p1 = std::move(p2); */
  /* p2 = std::move(p3); */
  /* p3 = std::move(p4); */
  /* p4 = std::move(p5); */

  /* p5 = std::move(p6); */
  /* p2 = std::move(p7); */
  /* p3 = std::move(p8); */
  /* p4 = std::move(p9); */

  /* p2 = std::move(p4); */
  /* p5 = std::move(p9); */
  /* p3 = std::move(p10); */
  /* p2 = std::move(p5); */
  auto t1 = high_resolution_clock::now();
  std::cout << duration_cast<milliseconds>(t1 - t0).count() << "ms\n";
}
// 13.54: not changing the swap version results in an ambiguous overload
