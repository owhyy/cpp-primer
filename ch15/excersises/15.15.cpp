#include <chrono>
#include <iostream>
#include <string>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}
  double net_price(std::size_t) const = 0;

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t) const override;

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

class Black_Friday : public Disc_quote {
public:
  Black_Friday() = default;
  Black_Friday(const std::string &book, double price, std::size_t qty,
               double disc = 0.5)
      : Disc_quote(book, price, qty, disc) {}

  double net_price(std::size_t) const override;

private:
  std::time_t tp = std::time(NULL);
  std::tm *ts = std::localtime(&tp);
  std::size_t min_qty = 0;
  double discount = 0.5;
};

double Black_Friday::net_price(std::size_t n) const {
  double ret_price = 0;
  if (ts->tm_mon + 1 == 11) {
    if (ts->tm_mday == 26) {
      ret_price = n * discount * price;
    }
  } else
    ret_price = n * price;
  return ret_price;
}
double print_total(std::ostream &os, const Quote &q, std::size_t n);
