#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::list;
using std::map;
using std::set;
using std::string;
using std::vector;

int main() {
  map<string, list<uint>> words_with_line_numbers;
  vector<string> word_occurences;
  int line_number = 0;
  string s;
  while (cin >> s) {
    ++line_number;
    words_with_line_numbers[s].push_back(line_number);
    word_occurences.push_back(s);
  }
  for (auto &i : words_with_line_numbers) {
    cout <<"The word " << i.first << ' ' << "appears at"<<(i.second.size() == 1? " line " : " lines ");
    for (auto j : i.second)
      cout << j << ' ';
    cout<<'\n';
  }
}
