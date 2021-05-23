

#include <iostream>
#include <string>
#include <vector>
class PrintStringIstream {
  public:
  PrintStringIstream(std::istream& s = std::cin)
      : is(s)
  {
  }

  std::string operator()() const
  {
    std::string str;
    std::getline(is, str);
    return is ? str : std::string();
  };

  private:
  std::istream& is;
};

int main(int argc, const char** argv)
{
  PrintStringIstream obj;
  std::vector<std::string> sv;
  for (int i = 0; i != 3; ++i) {
    sv.push_back(obj());
  }
  for (auto i : sv)
    std::cout << i << ' ';
  return 0;
}
