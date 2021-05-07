
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

map<string, string> convert_text_to_map(std::ifstream &in) {
  map<string, string> return_map;
  string key;
  string value;
  while (in >> key && getline(in, value))
    { 
      if(value.size())
        return_map[key] = value.substr(1); 
      else throw std::runtime_error("non-existent value for " + key);
    }
  return return_map;
}

string transform(const string &s, map<string, string> &word_map) {
  auto found = word_map.find(s);
  if (found != word_map.end())
    return found->second;
  else
    return s;
}

void change_string(std::ifstream &map_file, std::ifstream &text_file) {
  map<string, string> return_map = convert_text_to_map(map_file);
  string line;
  while (getline(text_file, line)) {
    std::istringstream iss(line);
    for (string word; iss >> word;) {
      cout << transform(word, return_map) << ' ';
    }
    cout << '\n';
  }
}

int main() {
  std::ifstream is("word_transformation.txt");
  std::ifstream file_name("text.txt");
  /* map<string, string> qq = convert_text_to_map(is); */

  change_string(is, file_name);

  /* for (auto i : qq) */
  /*   cout << i.first << ' ' << i.second << '\n'; */
}
