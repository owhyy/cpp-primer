#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::list;
using std::map;
using std::set;
using std::string;
using std::vector;

struct Sales_data{
  
  int Isbn()const{return isbn;}
  void set_Isbn(int i){this->isbn = i;}
  private:
  int isbn;
};

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs){
  return lhs.Isbn() < rhs.Isbn();
}

int main(){
  std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(*compareIsbn);
}
