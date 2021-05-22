
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

class Sales_data {
public:
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(std::string bookNo, unsigned units_sold, double revenue)
      : bookNo(), units_sold(), revenue() {}
  Sales_data(std::istream &) {}

  string ISBN() const { return this->bookNo; }
  Sales_data &combine(const Sales_data &);
  Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
  }

  double avg_price() const { return (units_sold ? revenue / units_sold : 0); };
  istream &read(istream &is, Sales_data &data) {
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    if (is)
      data.revenue = data.units_sold * price;
    else
      data = Sales_data();
    return is;
  }
  ostream &print(ostream &, const Sales_data &data);
};
Sales_data &Sales_data::combine(const Sales_data &rhs) {
  revenue += rhs.revenue;
  units_sold += rhs.units_sold;
  return *this;
}

ostream &Sales_data::print(ostream &os, const Sales_data &data) {
  os << data.bookNo << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

int main() {
  Sales_data data("12312", 3, 99);
  data.print(cout, data) << endl;

  return 0;
}
