
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
      std::transform(new_word.begin(), new_word.end(), new_word.begin(),
                     ::tolower);
      new_word.erase(std::remove_if(new_word.begin(), new_word.end(), ispunct),
                     new_word.end());
      new_word[0] = toupper(new_word[0]);
      ++word_count[new_word];
    }
    for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << '\n';
}
