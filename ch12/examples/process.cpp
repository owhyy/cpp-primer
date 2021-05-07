#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

/* void process(std::shared_ptr<int> p) { std::cout << p.use_count(); } */

int main() {

  auto sp = std::make_shared<int>(42);

  auto p = sp.get();
  delete p;
}
