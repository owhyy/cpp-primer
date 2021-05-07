#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

int main() {

  std::unique_ptr<std::string> p1(new std::string("Stegosaurus"));
  std::unique_ptr<std::string> p2(p1.release());
  std::unique_ptr<std::string> p3(new std::string("Trex"));

  std::string *p = p2.release();
  delete (p);
}
