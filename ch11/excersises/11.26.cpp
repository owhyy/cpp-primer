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
  map<string, int> str_int_map;
  str_int_map["Anna"]=3;
  int pos_anna=str_int_map["Anna"];
  cout<<pos_anna;
}
  // types that can be used to subscript are string and int
  // return type will be int
