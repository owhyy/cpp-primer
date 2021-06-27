#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename Iter, typename ValT>
Iter ufind(Iter b, Iter e, const ValT &v) {
  for (; b != e; ++b)
    if (v == *b)
      return b;
  return e;
}

int main() {
  std::vector<int> iv{1, 5, 99, 13};
  auto nf = ufind(iv.begin(), iv.end(), 10);
  auto f = ufind(iv.begin(), iv.end(), 5);

  std::list<std::string> sl{"lingua", "ignota", "journey"};
  auto lnf = ufind(sl.begin(), sl.end(), "shintaro");
  auto lf = ufind(sl.begin(), sl.end(), "lingua");
}
