#include "Basket.h"

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

void Basket::add_item(const Quote &sale) {
  items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::add_item(Quote &&sale) {
  items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}
