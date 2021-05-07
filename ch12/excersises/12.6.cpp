#include <iostream>
#include <new>
#include <string>
#include <vector>

std::vector<int> *VecPtr() {
  std::vector<int> *vecptr = new (std::vector<int>);
  return vecptr;
}

void read_from_input(std::vector<int> *vecptr) {
  int n;
  while (std::cin >> n)
    vecptr->push_back(n);
}

void write_to_screen(std::vector<int> *vecptr) {
  for (auto i : *vecptr)
    std::cout << i << ' ';
  delete[] vecptr;
}
int main() {
  std::vector<int> *vp = VecPtr();
  read_from_input(vp);

  write_to_screen(vp);
}
