#include <algorithm>
#include <list>
#include <iostream>
#include <string>

void removeDupls(std::list<std::string> &ls)
{
  ls.sort();
  ls.unique();
  for(const auto &i : ls)
    std::cout<<i<<std::endl;
}

int main()
{
  std::list<std::string> list{"ana", "ana", "are mute", "ana", "ere"};
  removeDupls(list);
 return 0; 
}
