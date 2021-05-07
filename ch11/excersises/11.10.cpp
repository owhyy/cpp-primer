#include <list>
#include <map>
#include <vector>
using std::list;
using std::map;
using std::vector;

int main() {
  map<vector<int>::iterator, int> it_to_int;  // both are definable, as we can see
  map<list<int>::iterator, int> ls_to_int;  
}
