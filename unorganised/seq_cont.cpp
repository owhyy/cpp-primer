#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
void removeDupls(std::vector<std::string> &v) {
  std::sort(v.begin(), v.end());
  auto pos_unique = std::unique(v.begin(), v.end());
  v.erase(pos_unique);
}
void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  removeDupls(words);
  auto wc =
      std::stable_partition(words.begin(), words.end(),
                     [sz](const std::string &s) { return s.size() >= sz; });
  auto count = wc - words.begin();
  std::cout << "there are " << count
            << " words of size greater than or equal to " << sz << '\n';
  std::for_each(words.begin(), wc,
                [](const std::string &s) { std::cout << s << " "; });
}
int main() {
  std::vector<std::string> v{"ana", "are", "mere", "mere", "nanas", "ananas"};
  biggies(v, 4);
}
