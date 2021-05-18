#include "String.h"
#include <iostream>
int main() {
  String s("Ana");
  for (auto i : s)
    std::cout << i;
}
