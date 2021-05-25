#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
int main()
{
  std::vector<int> ivec { 1, 2, 3, 4, 5, 999, 1203, 30000, 15039, 69420 };

  std::vector<std::string> svec { "ana", "pooh", "qt", "yeah",
    "ok", "no u", "pooh" };

  std::vector<int>::size_type count = std::count_if(
      ivec.begin(), ivec.end(),
      std::bind(std::greater<int>(), std::placeholders::_1, 1024));
  std::cout << count << '\n';

  std::string not_pooh = *std::find_if(svec.begin(), svec.end(),
      std::bind(std::not_equal_to<std::string>(),
          std::placeholders::_1, "pooh"));
  std::cout << not_pooh << '\n';

  std::vector<int> new_ivec;

  std::transform(ivec.begin(), ivec.end(), std::back_inserter(new_ivec),
      std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

  std::for_each(new_ivec.begin(), new_ivec.end(),
      [](int n) { std::cout << n << ' '; });
  std::cout << '\n';
}
