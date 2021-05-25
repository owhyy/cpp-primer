
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Sales_data {
  friend std::istream& operator>>(std::istream&, Sales_data&);
  friend std::ostream& operator<<(std::ostream&, const Sales_data&);

  public:
  Sales_data() = default;
  Sales_data(const std::string& s)
      : bookNo(s)
  {
  }
  Sales_data(std::string bookNo, unsigned units_sold, double price)
      : bookNo(bookNo)
      , units_sold(units_sold)
      , revenue(units_sold * price)
  {
  }
  Sales_data(std::istream&) { }
  inline Sales_data& operator=(const std::string&);
  string ISBN() const { return this->bookNo; }
  double avg_price() const { return (units_sold ? revenue / units_sold : 0); };

  operator string() const { return bookNo; }
  operator double() const { return revenue; }
  // operators

  Sales_data& operator+=(const Sales_data& rhs)
  {
    revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
  }

  private:
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data operator+(Sales_data lhs, const Sales_data& rhs)
{
  lhs += rhs;
  return lhs;
}

std::istream& operator>>(std::istream& is, Sales_data& sd)
{
  double price;
  is >> sd.bookNo >> sd.units_sold >> price;
  if (is && sd.bookNo.size() > 8)
    sd.revenue = sd.units_sold * price;
  else
    sd = Sales_data();
  return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& sd)
{
  os << sd.bookNo << " " << sd.units_sold << " " << sd.revenue << " "
     << sd.avg_price();
  return os;
}

inline Sales_data& Sales_data::operator=(const std::string& name)
{
  if (name.size() > 8)
    bookNo = name;

  return *this;
}
int main()
{
  Sales_data s1("192-333-AAAQO-69", 15, 10.5);
  Sales_data s2("7-213-II3O-199", 15, 10.5);
  std::cout << s1 + s2;
  return 0;
}
