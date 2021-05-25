#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
int main()
{
  std::function<double(double, double)> add = [](double a, double b) {
    return a + b;
  };
  std::function<double(double, double)> subtr = [](double a, double b) {
    return a - b;
  };
  std::function<double(double, double)> mult = [](double a, double b) {
    return a * b;
  };
  std::function<double(double, double)> div = [](double a, double b) {
    return a / b;
  };
  std::function<double(double, double)> modd = [](double a, double b) {
    return static_cast<int>(a) % static_cast<int>(b);
  };
  std::function<double(double, double)> exp = [](double a, double b = 0) {
    return pow(a, static_cast<int>(b));
  };

  std::map<std::string, std::function<double(double, double)>> calc;
  calc.insert({ "+", add });
  calc.insert({ "-", subtr });
  calc.insert({ "*", mult });
  calc.insert({ "/", div });
  calc.insert({ "%", modd });
  calc.insert({ "**", exp });

  std::cout << calc["+"](3, 5) << '\n';
  std::cout << calc["-"](13, 5) << '\n';
  std::cout << calc["*"](39, 2) << '\n';
  std::cout << calc["/"](30, 5) << '\n';
  std::cout << calc["%"](3, 9) << '\n';
  std::cout << calc["**"](3, 3) << '\n';
}
