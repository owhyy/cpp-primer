
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
  string family_last_name;
  string children_name;
  int nr_children;
  vector<string> family_last_names;
  vector<string> children_names;
  vector<string> found_last_names;
  std::multimap<string, vector<string>> Family;
  while (true) {
    cout << "Enter family last name(press x to stop):\n";
    cin >> family_last_name;
    if (family_last_name != "x") {
      family_last_names.push_back(family_last_name);
      cout << "Enter number of children:\n";
      cin >> nr_children;
      for (int i = 0; i != nr_children; ++i) {
        cout << "Enter name of kid " << i + 1 << ":\n";
        cin >> children_name;
        children_names.push_back(children_name);
      }
      Family.insert(std::make_pair(family_last_name, children_names));
    } else
      break;
  }

  while (true) {
    string sought_family_last_name;
    cout << "Enter sought last name(press x to stop):\n";
    cin >> sought_family_last_name;
    if (sought_family_last_name != "x") {
      if (find(family_last_names.begin(),
               family_last_names.end(), // if not found
               sought_family_last_name) == family_last_names.end()) {
        cout << "Family last name not found\n";
        return -1;
      } else { // if found
        cout << "Family found!\n";
        found_last_names.push_back(sought_family_last_name);
        cout << "Family " << found_last_names[found_last_names.size() - 1]
             << ":\n";
        cout << "Enter number of children: ";
        cin >> nr_children;
        for (int i = 0; i != nr_children; ++i) {
          cout << "Enter name of kid " << i + 1 << ":\n";
          cin >> children_name;
          children_names.push_back(children_name);
        }
        Family.insert(std::make_pair(family_last_name, children_names));
      }
    } else
      break;
  }

  for (auto &i : Family) {
    if (i.first != "x") { //dunno how to get rid of this. temporary fix, might come back later
      cout << "Family name: ";
      cout << i.first << '\n';
      cout << "Children: ";
      for (auto &j : i.second)
        cout << j << ' ';
      cout << "\n\n\n";
    }
  }
}
