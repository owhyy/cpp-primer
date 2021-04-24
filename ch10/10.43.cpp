#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using std::string;
using std::vector;
int main() {
  vector<int> vec{1, 2, 0, 4, 9, 5, 6, 8, 9};
  vector<int> vec2;
  vector<int>::reverse_iterator pos1 = vec.rbegin() + 2;
  vector<int>::reverse_iterator pos2= vec.rbegin() + 7;
  std::copy(vec.rbegin() + 2, vec.rbegin() + 7, std::back_inserter(vec2));
  for(auto i : vec2)
    std::cout<<i<<' ';
  return 0;
}
