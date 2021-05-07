#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;
int main() {
  map<string, vector<int>> str_vector_int_map;
  str_vector_int_map["Anna"]={9,2,3};
  int var = str_vector_int_map.find("Anna")->second[0];
  cout<<var; 
}
