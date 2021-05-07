#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
int main() {
  std::unordered_set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                   "the", "but", "and", "or", "an", "a"};
  std::unordered_map<std::string, size_t> word_count;
  std::string word;

  while (std::cin >> word)
    if (exclude.find(word) == exclude.end()) {
      std::string new_word = word;
      ++word_count[new_word];
    }
  for(auto i : word_count)
    std::cout<<i.first<<" appears "<<  i.second <<( i.second > 1 ? " times" : " time") << '\n';
}

