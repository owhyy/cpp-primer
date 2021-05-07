
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
/* #include <utility> */
int main() {
  std::map<std::string,size_t> word_count;
  word_count.insert(std::pair<std::string, int>("Ana", 3));
  std::string word;
  while (std::cin >> word)
    ++word_count[word];
  std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();
  while(map_it!=word_count.cend()){
    std::cout<<word<< " occurs "<<map_it->second<<" times\n";
    ++map_it;
  }

    /* for (const auto &w : word_count) */
    /* std::cout << w.first << " occurs " << w.second */
    /*           << ((w.second > 1) ? " times" : " time") << '\n'; */
}
