#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"
class Disc_quote : public Quote {
public:
  Disc_quote(){};
  Disc_quote(const std::string &b, double p, std::size_t q, double d)
      : Quote(b, p), quantity(q), discount(d){};

  // move constructor
  Disc_quote(Disc_quote &&s) noexcept
      : Quote(std::move(s)), quantity(std::move(s.quantity)),
        discount(std::move(s.discount)) {}
  // copy constructor
  Disc_quote(const Disc_quote &s)
      : Quote(s), quantity(s.quantity), discount(s.discount) {}
  // move assign
  Disc_quote &operator=(Disc_quote &&s) noexcept {
    if (*this != s) {
      Quote::operator=(std::move(s));
      quantity = std::move(s.quantity);
      discount = std::move(s.discount);
    }

    return *this;
  }
  // copy assign
  Disc_quote &operator=(const Disc_quote &s) {
    if (*this != s) {
      Quote::operator=(s);
      quantity = s.quantity;
      discount = s.discount;
    }

    return *this;
  }

  virtual double net_price(std::size_t n) const override = 0;
  std::size_t number_of_books() const { return quantity; }
  ~Disc_quote() {}

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

#endif // DISC_QUOTE_H
