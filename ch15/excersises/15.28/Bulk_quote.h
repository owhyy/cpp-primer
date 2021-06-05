#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() {}
  using Disc_quote::Disc_quote;
  // move constructor
  Bulk_quote(Bulk_quote &&s) noexcept : Disc_quote(std::move(s)) {}
  // copy constructor
  Bulk_quote(const Bulk_quote &s) : Disc_quote(s) {}
  // move assign
  Bulk_quote &operator=(Bulk_quote &&s) noexcept {
    if ((*this != s)) {
      Disc_quote::operator=(std::move(s));
    }
    return *this;
  }
  // copy assign
  Bulk_quote &operator=(const Bulk_quote &s) {
    if ((*this != s)) {
      Disc_quote::operator=(s);
    }
    return *this;
  }

  std::size_t number_of_books() const { return quantity; }
  double net_price(std::size_t) const override;
  ~Bulk_quote() override {}
};

#endif // BULK_QUOTE_H
