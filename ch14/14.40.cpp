#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class isShorter {
public:
  bool operator()(const std::string &s1, const std::string &s2) const {
    return s1.size() < s2.size();
  }
};

void elimDups(std::vector<std::string> &sv) {
  std::sort(sv.begin(), sv.end());
  auto end_uq = std::unique(sv.begin(), sv.end());
  sv.erase(end_uq, sv.end());
}
void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(), isShorter());
}
int main(int argc, const char **argv) { return 0; }
