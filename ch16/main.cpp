#include "strvec.h"
#include <iostream>
using namespace std;
int main() {

  StrVec<string> sv;
  sv.push_back("yeet");
  sv.push_back("yo mama");

  std::cout << *(sv.end() - 1);
}
