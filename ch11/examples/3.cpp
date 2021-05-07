#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
int main() {
  std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                   "the", "but", "and", "or", "an", "a"};
  std::set<char> punctuation = {',', '.', ':', ';', '?', '!'};
  std::map<std::string, size_t> word_count;
  std::string word;

  while (std::cin >> word)
    if (exclude.find(word) == exclude.end()) {
      std::string new_word = word;
      ++word_count[new_word];
    }
  auto map_it = word_count.begin();
  std::cout<<map_it->first;
  std::cout<<' '<<map_it->second;
  map_it->first = "new key"; // can't change key
  ++map_it->second; // can change value
}
