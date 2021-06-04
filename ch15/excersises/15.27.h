
// idk why I get errors.. probably will check again later sometime
#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <utility>

class Quote {
  friend bool operator!=(const Quote &lhs, const Quote &rhs) {
    return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
  }

public:
  Quote() {
    std::cout << "Quote default constructor\n";
  } // this initializes bookNo and price to default values
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {
    std::cout << "Quote 2 parameter constructor\n";
  }
  Quote(const Quote &);
  Quote &operator=(const Quote &);
  Quote(Quote &&) noexcept;
  Quote &operator=(Quote &&) noexcept;

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual ~Quote() { std::cout << "Quote destructor\n"; }

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

class Disc_quote : public Quote {
public:
  Disc_quote() =
      default; // this initializes quantity and discount to default values
  // not initializing it would initialize quantity to a undefined value

  Disc_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}
  Disc_quote(const Disc_quote &);
  Disc_quote &operator=(const Disc_quote &);
  Disc_quote(Disc_quote &&) noexcept;
  Disc_quote &operator=(Disc_quote &&) noexcept;
  ~Disc_quote() { std::cout << "Disc_quote distructor\n"; }
  double net_price(std::size_t) const override = 0;

  std::pair<size_t, double> discount_policy() const {
    return {quantity, discount};
  }

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() { std::cout << "Bulk_quote default constructor\n"; };
  /* Bulk_quote(const std::string &book, double price, std::size_t qty, */
  /*            double disc) */
  /*     : Disc_quote(book, price, qty, disc) { */
  /*   std::cout << "Bulk_quote constructor taking 4 parameters\n"; */
  /* } */
  using Disc_quote::Disc_quote;
  Bulk_quote(const Bulk_quote &);
  Bulk_quote &operator=(const Bulk_quote &);
  Bulk_quote(Bulk_quote &&) noexcept;
  Bulk_quote &operator=(Bulk_quote &&) noexcept;
  ~Bulk_quote() override { std::cout << "Bulk_quote destructor\n"; }
  double net_price(std::size_t) const override;

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &q, std::size_t n);

#endif
