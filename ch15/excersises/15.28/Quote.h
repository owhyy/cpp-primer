#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
  friend bool operator!=(const Quote &lhs, const Quote &rhs);

public:
  // base constructors
  Quote(){};
  Quote(const std::string &b, double p) : bookNo(b), price(p){};
  // move constructor
  Quote(Quote &&s) noexcept
      : bookNo(std::move(s.bookNo)), price(std::move(s.price)) {}
  // copy constructor
  Quote(const Quote &s) : bookNo(s.bookNo), price(s.price) {}
  // move assign
  Quote &operator=(Quote &&s) noexcept {
    if (*this != s) {
      bookNo = std::move(s.bookNo);
      price = std::move(s.price);
    }
    return *this;
  }
  // copy assign
  Quote &operator=(const Quote &s) {
    if (*this != s) {
      bookNo = s.bookNo;
      price = s.price;
    }
    return *this;
  }

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual ~Quote() {}

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

bool inline operator!=(const Quote &lhs, const Quote &rhs) {
  return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

#endif // QUOTE_H
