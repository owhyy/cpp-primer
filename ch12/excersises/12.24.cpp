#include <cstring>
#include <iostream>
#include <string>
int main() {

  std::string s;
  std::getline(std::cin, s);

  uint sz = s.size() + 1;

  char *arr = new char[sz];
  strcpy(arr, s.data());
  for (auto *i = arr; i != arr + sz; ++i)
    std::cout << *i;

  delete[] arr;
}
