
#include <iostream>
#include <memory>
#include <new>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {

  int n = 4;
  std::allocator<string> alloc;
  auto const p = alloc.allocate(n);
  auto q = p;

  string s;
  while (cin >> s && q != p + n) {
    alloc.construct(++q, s);
  }
  for (int i = 0; i != n; ++i)
    cout << *q;
  /* const size_t size = q - p; */
  /* cout << size; */

  while (q != p)
    alloc.destroy(q--);
  alloc.deallocate(p, n);
}
