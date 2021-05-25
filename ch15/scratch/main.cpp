#include "Quote.h"
#include <string>

int main() {
  Bulk_quote bbq;
  Quote q("6969420", 42.69);

  print_total(std::cout, bbq, 5);
  print_total(std::cout, q, 13);
}
