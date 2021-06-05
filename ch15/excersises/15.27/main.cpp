#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Quote.h"

int main() {
  Bulk_quote bq1;
  Bulk_quote bq2 = bq1;
  bq1 = bq2;
  bq2 = std::move(Bulk_quote());
  /* Bulk_quote bq2 = std::move(bq1); */
}

/* Basically, the inheritance works this way :
 * First, base class members of the objects get initialized and constructed
 * Also, the base-class members are the one who get copied and moved
 * firsthandly. Then, the members of the classes derived from the base class get
 * copied, constructed etc. But the distructor works in reverse order,
 * destroying the derived part first, and then, at last, the base class part
 * However, the assignment operators used on derived class use ONLY the
 * derived-class version
 */
