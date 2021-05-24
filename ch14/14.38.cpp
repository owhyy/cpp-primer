#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class BoundTest {

public:
  bool operator()(const std::string &s, size_t r1, size_t r2) const {
    return s.size() <= r1 || s.size() >= r2;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::string line;
  int count = 0;
  std::vector<std::string> sv;
  while (in >> line) {
    BoundTest b;
    if (b.operator()(line, 9, 10))
      ++count;
  }
  std::cout << count;
}
