#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include "../ch10/Sales_item.h"
using std::vector;
using std::string;
using namespace std::placeholders;

int main()
{
  std::istream_iterator<Sales_item> s_in(std::cin), s_eof;
  vector<Sales_item> sv(s_in, s_eof);
  sort(sv.begin(), sv.end(), compareIsbn);
  for(auto beg = sv.cbegin(), end = beg; beg!=sv.cend(); beg=end)
  {
  end = find_if(beg, sv.cend(), [beg](const Sales_item &item) {return item.isbn() != beg->isbn();});
  std::cout<<std::accumulate(beg, end, Sales_item(beg->isbn())) << '\n';
  }
  return 0;
}
