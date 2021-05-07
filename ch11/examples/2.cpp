
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using std::pair;
using std::string;
using std::vector;
pair<string, int> process(vector<string> &v) {
  if (v.empty())
    return {v.back(), v.back().size()};
  else
    return pair<string,
                int>(); // explicitly initialize (stirng to "" and int to 0)
  // why does int get initialized to 0 here?
}

int main() {
  vector<string> sv{};

  pair<string, int> sp = process(sv);

  std::cout << sp.first << ' ' << sp.second << '\n';
}
