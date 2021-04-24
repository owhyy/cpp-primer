#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std::placeholders;

bool is_greater(const std::string &s, std::string::size_type sz = 6) {
  return s.size() >= sz;
}
int main() {
  std::vector<std::string> sv{"aaaana", "ardsdse", "medsadasre"};
  auto f = std::bind(&is_greater, _1, 6);
  auto fpos = std::find_if(sv.begin(), sv.end(), f);
  std::cout<<*fpos<<'\n';

}

