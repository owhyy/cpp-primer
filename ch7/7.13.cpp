
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

class Sales_data
{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {cout<<"Main constructor got initialized!\n";}
    Sales_data() : Sales_data("", 0, 0) { cout << "Default nondelegating constructor got initialized!\n "; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) { cout << "String nondelegating constructor got initialized!\n"; }
    Sales_data(std::istream &) : Sales_data() { cout << "Istream nondelegating constructor got initialized!\n"; }
    Sales_data(unsigned n) : Sales_data("", n, 0) { cout << "Units-sold constructor got initialized!\n"; }
    Sales_data(unsigned n, double p) : Sales_data("", n, p) { cout << "Units sold and revenue constructor got initialized!\n"; }
    Sales_data(const string &s, unsigned n) : Sales_data(s, n, 0) { cout << "ISBN and units-sold nondelegating constructor got initialized!\n"; }
    Sales_data(const string &s, double p) : Sales_data(s, 0, p) { cout << "ISBN and revenue got initialized!\n"; }
    Sales_data(unsigned n, const string &s) : Sales_data(s, n, 0) {cout<<"ISBN and units-sold nondelegating constr\n";}
    Sales_data(unsigned n, double p, const string &s) : Sales_data(s, n, p){cout<<"Units sold, revenue then name\n";}
    Sales_data(double p, unsigned n, const string &s) : Sales_data(s, n, p){cout<<"Revenue, units sold and then name\n";}
    Sales_data(unsigned n, const string &s, double p) : Sales_data(s, n, p){cout<<"Units sold, name, then revenue\n";}

    string ISBN() const { return this->bookNo; }
    Sales_data &combine(const Sales_data &);
    Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
    {
        Sales_data sum = lhs;
        sum.combine(rhs);
        return sum;
    }

    double avg_price() const
    {
        return (units_sold ? revenue / units_sold : 0);
    };
    istream &read(istream &, Sales_data &);
    ostream &print(ostream &, const Sales_data &data);
};
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
}

istream &Sales_data::read(istream &is, Sales_data &data)
{
    is >> data.bookNo >> data.units_sold >> data.revenue;
    return is;
}
ostream &Sales_data::print(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold
       << " " << data.revenue << " " << data.avg_price();
    return os;
}

int main()
{

    Sales_data d1(3, 9.3, "yes");
    // Sales_data total;
    // if (total.read(cin, total))
    // {
    //     Sales_data trans;
    //     while (trans.read(cin, trans))
    //     {
    //         if (total.ISBN() == trans.ISBN())
    //             total.combine(trans);
    //         else
    //         {
    //             total.print(cout, total) << endl;
    //             total = trans;
    //         }
    //     }
    //     total.print(cout, total) << endl;
    // }
    // else
    // {
    //     cerr << "No data" << endl;
    // }

    return 0;
}