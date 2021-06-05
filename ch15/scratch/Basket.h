#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"
#include <memory>
#include <set>
class Basket {
public:
  void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
  double total_recepit(std::ostream &) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_recepit(std::ostream &os) const {
  double sum = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend();
       iter = items.upper_bound(
           *iter)) { // upper_bound ignores elements that have the same key,
                     // going straight to the next diferent element
    sum += print_total(os, **iter, items.count(*iter));
  }
  os << "Total Sale: " << sum << '\n';
  return sum;
}
