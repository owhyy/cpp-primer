#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
using std::string;
using std::vector;


void vec2list(vector<string> &sv, std::list<string> &sl)
{
  std::sort(sv.begin(), sv.end());
  std::unique_copy(sv.begin(), sv.end(), std::back_inserter(sl));
}

int main()
{
  vector<int> vseq{0,1,2,3,4,5,6,7,8,9};
  std::deque<int> ideq;
  /* std::copy(vseq.begin(),vseq.end(), std::back_inserter(ideq)); */
  /* std::copy(vseq.rbegin(),vseq.rend(), std::front_inserter(ideq)); */
  std::copy(vseq.begin(),vseq.end(), std::inserter(ideq, ideq.begin()));
  for(const auto &i : ideq)
    std::cout<<i<<" ";
  return 0;
}
