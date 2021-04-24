#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::ifstream in("10.33.in");
  std::ofstream out_even("even.out");
  std::ofstream out_odd("odd.out");
  std::istream_iterator<int> int_it(in), int_eof;
  std::ostream_iterator<int> even_it(out_even, "\n");
  std::ostream_iterator<int> odd_it(out_odd, " ");
  std::vector<int> vec(int_it, int_eof);
  auto it = vec.begin();
  while (it != vec.end()) {
    if (*it % 2 == 0) {
      *even_it++ = *it;
    } else
      *odd_it = *it;
    ++it;
  }
  /* std::copy(vec.begin(), vec.end(), even_it); */
  /* else std::copy(vec.begin(), vec.end(), odd_it); */
  return 0;
}
