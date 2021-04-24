#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using std::string;
using std::vector;

int main() {
  std::istream_iterator<int> int_it(std::cin), eof;
  vector<int> vec(int_it, eof);
  std::ostream_iterator<int> int_out(std::cout, " ");
  std::copy(vec.begin(), vec.end(), int_out);
  std::cout << '\n';
  return 0;
}
