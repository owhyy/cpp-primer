
#include "String.h"
#include <string>
#include <vector>
int main() {
  std::vector<String> sv;
  sv.reserve(3);
  std::string &&sr = "ana";
  sv.push_back("ana");
  sv.push_back("are");
  sv.push_back("mere");
}
