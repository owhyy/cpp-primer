#include <algorithm>
#include <iostream>
#include <vector>
class TestForEquality {
  public:
  TestForEquality(int v)
      : val(v)
  {
  }
  bool operator()(int elem) { return val == elem; }

  private:
  int val;
};

int main()
{
  TestForEquality qq(1);
  std::vector<int> vec { 1, 3, 5, 9, 199 };
  std::cout << *std::find_if(vec.begin(), vec.end(), TestForEquality(199));
}
