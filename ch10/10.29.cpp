#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>
int main()
{
  std::ifstream in("10.29.in");
  std::istream_iterator<std::string> s_in(in), s_eof;
  std::vector<std::string> vec(s_in, s_eof);

  std::ostream_iterator<std::string> s_out(std::cout, " ");
  std::copy(vec.begin(), vec.end(), s_out);
  


  return 0;    
}
