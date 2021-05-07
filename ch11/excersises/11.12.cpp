#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::list;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main() {
  int n;
  string s;
  vector<pair<string, int>> pair_vector;
  pair<string, int> string_int_pair;
  while (cin >> s >> n) {
    string_int_pair.first = s;
    string_int_pair.second = n;
    string_int_pair={s,n}; //this seems easiest
    string_int_pair={{s},{n}};
    pair_vector.push_back(string_int_pair);
  }
  for(const auto &i : pair_vector)
    cout<<i.first<<' '<<i.second<<'\n';
}
