#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
int main() {
  std::unique_ptr<std::string> sq1(new std::string("Anna"));
  std::unique_ptr<std::string> sq2(sq1.release());
  std::unique_ptr<int> ppp(1024);
  sq2.reset(sq1);

  std::unique_ptr<std::string> sq3(sq1.reset());
  std::cout << *sq2;
}
