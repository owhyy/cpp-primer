#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

int main()
{
  std::istream_iterator<int> int_in(std::cin), eof;
  std::vector<int>v (int_in, eof);
  std::sort(v.begin(), v.end());
  std::ostream_iterator<int> int_out(std::cout, " ");
  std::unique_copy(v.begin(), v.end(), int_out);


  return 0;
}
