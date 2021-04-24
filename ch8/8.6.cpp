
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

class Sales_data
{
    inline friend Sales_data add(const Sales_data&, const Sales_data&);
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &){ }

    string ISBN() const { return this->bookNo; }
    Sales_data &combine(const Sales_data &);
    inline Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    istream &read(istream &, Sales_data &);
    ostream &print(ostream &, const Sales_data &data);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price() const{ return (units_sold ? revenue / units_sold : 0);}

};

Sales_data Sales_data::add(const Sales_data &lhs, const Sales_data &rhs)
{
        Sales_data sum = lhs;
        sum.combine(rhs);
        return sum;
}


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

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    Sales_data total;
    if (total.read(in, total))
    {
        Sales_data trans;
        while (trans.read(in, trans))
        {
            if (total.ISBN() == trans.ISBN())
                total.combine(trans);
            else
            {
                total.print(out, total) << endl;
                total = trans;
            }
        }
        total.print(out, total) << endl;
    }
    else
    {
        cerr << "No data" << endl;
    }

    return 0;
}