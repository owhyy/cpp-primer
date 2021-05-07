#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>
int main(){
  std::set<int> iset{0,1,2,3,4,5,6,7,8,9};
  std::set<int>::iterator set_it = iset.begin();
  if(set_it!=iset.end())
  { 
    *set_it = 42; // error, can't change key
    std::cout<<*set_it;
  }
}
