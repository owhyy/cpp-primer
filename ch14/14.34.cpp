#include <iostream>
#include <string>
class IfThenElse {
  public:
  std::string operator()(bool cond, const std::string& p1,
      const std::string& p2)
  {
    return cond ? p1 : p2;
  }
};

int main()
{
  IfThenElse obj;
  std::cout << obj(1 < 2, "Yes", "No");
}
