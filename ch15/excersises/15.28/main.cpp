#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"
#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

int main() {
  std::vector<Quote> qv;
  std::vector<std::shared_ptr<Quote>> spqv;

  for (int i = 1; i != 10; ++i)
    qv.push_back(Bulk_quote("aaa", i * 10, 10, 0.3));
  double total = 0;
  for (const auto &b : qv)
    total += b.net_price(10);

  std::cout << total << '\n';

  // ----

  for (int i = 1; i != 10; ++i)
    spqv.push_back(std::make_shared<Bulk_quote>("aaa", i * 10, 10, 0.3));
  double total_p = 0;

  for (const auto &b : spqv)
    total_p += b->net_price(10);
  std::cout << total_p << '\n';
}
