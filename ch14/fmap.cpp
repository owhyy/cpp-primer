#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
int add(int i, int j) { return i + j; };
struct div {
  int operator()(int denom, int divis) { return denom / divis; }
};
int main()
{
  std::map<std::string, int (*)(int, int)> binops;
  auto mod = [](int i, int j) { return i % j; };

  binops.insert({ "+", add });
  binops.insert({ "%", mod });
}
