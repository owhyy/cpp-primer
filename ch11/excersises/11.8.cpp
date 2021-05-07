// No need to use a vector, since there will be no insertions
// since set is immutable, and we don't need insertions -> use set
// Also, nicer find()

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;
using std::set;

int main(){
  vector<string> excluded_words_vector{"A", "An", "The", "And", "a", "an", "the", "and"};
  set<string> excluded_words_set{ "A", "An", "The", "And", "a", "an", "the", "and" };
  int excluded_word_count=0;
  string s;
  while(cin>>s){
    if(excluded_words_set.find(s)==excluded_words_set.end()) // easy peasy find
    ++excluded_word_count;
  }
  while(cin>>s){
    if(excluded_words_vector.find(s)==excluded_words_vector.end()) // can't do this
    ++excluded_word_count;
  }
}
