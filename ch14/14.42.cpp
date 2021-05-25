#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
int main()
{
  std::vector<int> ivec { 3, 5, 91, 69, 0, 13, 9 };
  int n = 3;
  std::modulus<int> mod;
  auto pred = [&](int i) { return mod(n, i) == 0; };
  auto is_div = std::any_of(ivec.begin(), ivec.end(), pred);
  std::cout << (is_div ? "Is divisible" : "Is not divisible") << '\n';
}
