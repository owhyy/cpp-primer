#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &);
  HasPtr(HasPtr &&) noexcept;
  HasPtr &operator=(HasPtr &&) noexcept;
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() { delete ps; }

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
HasPtr::HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

HasPtr &HasPtr::operator=(const HasPtr &orig) {

  ps = new std::string(*orig.ps);
  i = orig.i;
  return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  std::cout << "Swapping " << *lhs.ps << " to " << *rhs.ps << '\n';
  using std::swap;
  swap(lhs.ps,
       rhs.ps); // swaps the pointers, doesn't create and allocate a new object
  swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
  p.i = 0;
  p.ps = 0;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
  swap(*this, rhs);
  return *this;
}

int main() {
  srand(time(NULL));
  std::vector<HasPtr> hptr_v;
  for (int i = 0; i != 5; ++i)
    hptr_v.push_back(HasPtr(std::to_string(i + rand() % 100)));
  std::sort(hptr_v.begin(), hptr_v.end());
  for (const auto i : hptr_v)
    std::cout << i;
}
