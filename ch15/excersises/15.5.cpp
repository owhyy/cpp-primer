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

class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &, double, std::size_t, double);
  double net_price(std::size_t) const override;

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &q, std::size_t n) {
  double ret = q.net_price(n);
  os << "ISBN: " << q.isbn() << " # sold: " << n
     << " total due: " << q.net_price(n) << '\n';
  return ret;
}

int main() {
  Bulk_quote bbq;
  Quote q("6969420", 42.69);

  print_total(std::cout, bbq, 5);
  print_total(std::cout, q, 13);
}
