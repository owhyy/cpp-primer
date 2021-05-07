#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
int main() {
 std::map<std::string, size_t> word_count;
  std::string word;

  while (std::cin >> word){
    ++word_count.insert({word,0}).first->second;
    /* auto status = word_count.insert({word, 1}); */
    /* if(!status.second) */
    /*   ++status.first->second; */
  } // first one is easier
  for (const auto &w : word_count)
  std::cout << w.first << " occurs " << w.second<< ((w.second > 1) ? " times" : " time") << '\n';
  
  std::map<std::string, std::vector<int>> mmm;
  std::string tmp = "ana";
  std::vector<int> qqq{1,2,3};
  mmm.insert(std::pair<std::string, std::vector<int>>(tmp, qqq));
  //types for map<string, vector<int>> :
  //1. argument:
  //pair<string, vector<int>>, {string, vector<int>}, make_pair(string, vector<int>, map<string, vector<int>::value_type(string, vector<int>)) 
  //2. return value:
  //pair<map<string, vector<int>>::iterator, bool>, void
}
