#include <iostream>
#include <string>
class Discount {
  friend std::ostream &operator<<(std::ostream &os, const Discount &obj) {
    os << obj.bookNo << ' ' << obj.count << ' ' << obj.revenue;
    return os;
  }

public:
  Discount() = default;

  Discount(const std::string &isbn, double price, std::size_t count)
      : bookNo(isbn), count(count) {
    if (count <= min_disc) {
      revenue = count * price * (1 - disc);
    } else
      revenue = count * price;
  }

private:
  std::string bookNo;
  std::size_t count;
  std::size_t min_disc = 5;
  double revenue;
  double disc = 0.05;
};
int main() {
  Discount d1("AAA-XXA", 15, 5);
  Discount d2("OOU-WITCH", 19.25, 2);
  Discount d3("ATT-CH9II", 7, 10);

  std::cout << d1 << '\n';
  std::cout << d2 << '\n';
  std::cout << d3 << '\n';
}
