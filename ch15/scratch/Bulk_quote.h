#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() { std::cout << "Bulk_quote default constructor\n"; }
  // move constructor
  Bulk_quote(Bulk_quote &&s) noexcept : Disc_quote(std::move(s)) {
    std::cout << "Bulk_quote move constructor\n";
  }
  // copy constructor
  Bulk_quote(const Bulk_quote &s) : Disc_quote(s) {
    std::cout << "Bulk_quote copy constructor\n";
  }
  // move assign
  Bulk_quote &operator=(Bulk_quote &&s) noexcept {
    if ((*this != s)) {
      Disc_quote::operator=(std::move(s));
    }
    std::cout << "Bulk_quote move assign\n";
    return *this;
  }
  // copy assign
  Bulk_quote &operator=(const Bulk_quote &s) {
    if ((*this != s)) {
      Disc_quote::operator=(s);
    }
    std::cout << "Bulk_quote copy assign\n";
    return *this;
  }

  double net_price(std::size_t) const override;
  ~Bulk_quote() override { std::cout << "Bulk_quote destructor\n"; }
};

#endif // BULK_QUOTE_H
