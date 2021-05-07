#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>
std::shared_ptr<std::vector<int>> VecPtr() {
  std::shared_ptr<std::vector<int>> vecptr =
      std::make_shared<std::vector<int>>();
  return vecptr;
}

void read_from_input(std::shared_ptr<std::vector<int>> vecptr) {
  int n;
  while (std::cin >> n)
    vecptr->push_back(n);
}

void write_to_screen(std::shared_ptr<std::vector<int>> vecptr) {
  for (auto i : *vecptr)
    std::cout << i << ' ';
}
int main() {
  std::shared_ptr<std::vector<int>> vp = VecPtr();
  read_from_input(vp);

  write_to_screen(vp);
}
