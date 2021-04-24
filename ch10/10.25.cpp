#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std::placeholders;
bool scheck_size(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}
bool check_size(const std::string &s, std::string::size_type sizez) {
  return s.size() >= sizez;
}

void biggies(std::vector<std::string> &sv,
             std::vector<std::string>::size_type sz) {
  std::sort(sv.begin(), sv.end());
  auto uq = std::unique(sv.begin(), sv.end());
  sv.erase(uq, sv.end());
  std::stable_sort(sv.begin(), sv.end(), std::bind(scheck_size, _1, _2));

  auto wc =
      std::partition(sv.begin(), sv.end(), std::bind(&check_size, _1, sz));

  auto count =
      std::count_if(sv.begin(), sv.end(), std::bind(check_size, _1, sz));
  std::cout << "there are " << count << " words longer than " << sz << '\n';
  std::for_each(sv.begin(), wc,
                [](const std::string &s) { std::cout << s << '\n'; });
}
int main() {
  std::vector<std::string> v{"ana", "aarere", "multe", "mere",
                             "no",  "u",      "ana",   "cucumber"};
  biggies(v, 3);
  return 0;
}
