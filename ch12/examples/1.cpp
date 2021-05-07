
#include <memory>
#include <string>
int main() {
  std::shared_ptr<std::string> p1;

  std::shared_ptr<int> p2 = std::make_shared<int>(42);

  if (p1 && p1->empty())
    *p1 = "hi";
  std::string *ps = new std::string;
  int *pi = new int;
  int *pq = new int(21012);
}
