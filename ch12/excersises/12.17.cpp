#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main() {
  typedef std::unique_ptr<int> IntP;
  int ix = 1024, *p1 = &ix, *p2 = new int(2048);
  /* IntP ip0(ix); */

  auto test = std::make_unique<int>(42);
  test(p1);
  IntP ip1(p2);
  IntP ip2(p1);
  IntP ip3(new int(40));
  /* IntP ip4(p2.get()); */
}
