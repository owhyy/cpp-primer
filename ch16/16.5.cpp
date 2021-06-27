
#include <iostream>
template <typename T> void print(const T &arr) {
  if (arr)
    for (const auto &elem : arr)
      std::cout << elem << ' ';
  std::cout << '\n';
}

// does not work on dinamic arrays

int main() {
  int iarr[3] = {89, 3, 39};
  print(iarr);
  char carr[6] = {"matre"};
  print(carr);
}
