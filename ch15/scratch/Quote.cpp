#include "Quote.h"
#include <iostream>
#include <string>

double print_total(std::ostream &os, const Quote &q, std::size_t n) {
  double ret = q.net_price(n);
  os << "ISBN: " << q.isbn() << " # sold: " << n
     << " total due: " << q.net_price(n) << '\n';
  return ret;
}
