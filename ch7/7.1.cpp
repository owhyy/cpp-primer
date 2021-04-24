#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

struct Sales_Data
{

    Sales_Data &combine(const Sales_Data &);
    string isbn() const { return bookNo; };

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_Data &Sales_Data::combine(const Sales_Data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
int main()
{
    ostream &print(ostream &, const Sales_Data &);
    istream &read(istream &, Sales_Data &);

    Sales_Data total;

    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_Data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
            cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
        }
    }
    return 0;
}