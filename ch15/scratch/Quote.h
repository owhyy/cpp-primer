#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
  friend bool operator!=(const Quote &lhs, const Quote &rhs);

public:
  // base constructors
  Quote() { std::cout << "Quote default constructor\n"; };
  Quote(const std::string &b, double p) : bookNo(b), price(p) {
    std::cout << "Quote constructor taking 2 elements\n";
  };
  // move constructor
  Quote(Quote &&s) noexcept
      : bookNo(std::move(s.bookNo)), price(std::move(s.price)) {
    std::cout << "Quote move constructor\n";
  }
  // copy constructor
  Quote(const Quote &s) : bookNo(s.bookNo), price(s.price) {
    std::cout << "Quote copy constructor\n";
  }
  // move assign
  Quote &operator=(Quote &&s) noexcept {
    if (*this != s) {
      bookNo = std::move(s.bookNo);
      price = std::move(s.price);
    }
    std::cout << "Quote move assign operator\n";
    return *this;
  }
  // copy assign
  Quote &operator=(const Quote &s) {
    if (*this != s) {
      bookNo = s.bookNo;
      price = s.price;
    }
    std::cout << "Quote copy assign operator\n";
    return *this;
  }

  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual ~Quote() { std::cout << "Quote destructor\n"; }

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

bool inline operator!=(const Quote &lhs, const Quote &rhs) {
  return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}

double print_total(std::ostream &os, const Quote &q, size_t n) {
  double ret = q.net_price(n);
  os << "ISBN: " << q.isbn() << " # sold: " << n << " total price: " << ret
     << '\n';
  return ret;
}

#endif // QUOTE_H
