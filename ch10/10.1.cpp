#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
void fc() {
  size_t v1 = 42;
  auto f = [v1]() mutable {
    while (v1)
      --v1;
    return v1 ? 0 : 1;
  };
  auto j = f();
  std::cout << j << '\n';
}

void biggies(std::vector<std::string> &sv,
             std::vector<std::string>::size_type sz) {
  std::sort(sv.begin(), sv.end());
  auto uq = std::unique(sv.begin(), sv.end());
  sv.erase(uq, sv.end());

  std::stable_sort(sv.begin(), sv.end(),
                   [](const std::string &s1, const std::string &s2) {
                     return s1.size() < s2.size();
                   });

  auto wc = std::find_if(sv.begin(), sv.end(),
                         [sz](const std::string &s) { return s.size() >= sz; });

  auto count = std::count_if(sv.begin(), sv.end(), [sz](const std::string &s) {
    return s.size() >= sz;
  });
  std::cout << "there are " << count << " words longer than " << sz << '\n';
  std::for_each(wc, sv.end(),
                [](const std::string &s) { std::cout << s << '\n'; });
}
int main() {
  std::vector<std::string> v{"ana", "aarere", "multe", "mere",
                             "no",  "u",      "ana",   "cucumber"};
  biggies(v, 3);
  return 0;
}
