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
  
  map<string, size_t> string_to_int_map;
  vector<int> iv;
  int n; 
  string s;
  while(cin>>s)
    ++string_to_int_map[s];

  auto m_it=string_to_int_map.cbegin();
  while(m_it!=string_to_int_map.cend())
  {
    iv.push_back(m_it->second);
    ++m_it;
  }
  for(auto i : iv)
    cout<<i<<' ';
}
