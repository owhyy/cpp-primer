#include "12.19.h"
#include <fstream>

StrBlob read_file(std::ifstream &file) {
  std::string s;
  StrBlob obj;
  while (file >> s)
    obj.push_back(s);
  return obj;
}

void print(StrBlob obj) {
  auto ptr = obj.begin();
  while (ptr != obj.end()) {
    std::cout << ptr.deref() << '\n';
    ptr.incr();
  }
}

int main() {
  std::ifstream file("in.txt");
  StrBlob bb = read_file(file);

  print(bb);
}
