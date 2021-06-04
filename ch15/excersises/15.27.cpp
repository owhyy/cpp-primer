#include "15.27.h"
#include <iostream>
#include <string>

double print_total(std::ostream &os, const Quote &q, std::size_t n) {
  double ret = q.net_price(n);
  os << "ISBN: " << q.isbn() << " # sold: " << n
     << " total due: " << q.net_price(n) << '\n';
  return ret;
}

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {
  std::cout << "Quote copy constructor\n";
}

Quote &Quote::operator=(const Quote &rhs) {
  if (*this != rhs) {
    bookNo = rhs.bookNo;
    price = rhs.price;
  }
  std::cout << "Quote copy assign constructor\n";
  return *this;
}

Quote::Quote(Quote &&rhs) noexcept
    : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
  std::cout << "Quote move constructor\n";
}

Quote &Quote::operator=(Quote &&rhs) noexcept {
  bookNo = std::move(rhs.bookNo);
  price = std::move(rhs.price);
  std::cout << "Quote move assign constructor\n";

  return *this;
}

Disc_quote::Disc_quote(const Disc_quote &rhs)
    : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {
  std::cout << "Disc_quote copy constructor\n";
}

Disc_quote &Disc_quote::operator=(const Disc_quote &rhs) {

  Quote::operator=(rhs);
  this->quantity = rhs.quantity;
  this->discount = rhs.discount;

  std::cout << "Bulk_quote copy-assign constructor\n";

  return *this;
}

Disc_quote::Disc_quote(Disc_quote &&rhs) noexcept
    : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)),
      discount(std::move(rhs.discount)) {
  std::cout << "Disc_quote move constructor\n";
}

Disc_quote &Disc_quote::operator=(Disc_quote &&rhs) noexcept {
  if (*this != rhs) {
    Quote::operator=(std::move(rhs));
    this->quantity = std::move(rhs.quantity);
    this->discount = std::move(rhs.discount);
  }
  std::cout << "Disc_quote move constructor\n";

  return *this;
}

Bulk_quote::Bulk_quote(const Bulk_quote &rhs)
    : Disc_quote(rhs), min_qty(rhs.min_qty) {
  std::cout << "Bulk_quote copy constructor\n";
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs) {
  std::cout << "Bulk_quote copy-assign constructor\n";
  Disc_quote::operator=(rhs);
  min_qty = rhs.min_qty;

  return *this;
}

Bulk_quote::Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs)) {
  std::cout << "Bulk_quote move constructor\n";
  min_qty = std::move(rhs.min_qty);
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept {
  Disc_quote::operator=(std::move(rhs));
  min_qty = rhs.min_qty;
  std::cout << "Bulk_quote move-assign constructor\n";

  return *this;
}
