#include "Bulk_quote.h"
double Bulk_quote::net_price(std::size_t n) const {
  return n * price * (n >= quantity ? 1 - discount : 1);
}
