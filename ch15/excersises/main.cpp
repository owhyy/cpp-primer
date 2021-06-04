#include "15.15.cpp"
#include <ctime>
#include <iostream>
int main() {
  Black_Friday bf("The Cather in The Rye", 5.4, 3);
  Disc_quote();
  std::cout << bf.net_price(3);
}
