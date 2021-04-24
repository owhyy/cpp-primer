#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int func(int, int);
typedef decltype(func) FP;

int Add(int n, int m)
{
    return (n + m);
}

int Subtr(int n, int m)
{
    return (n - m);
}

int Mult(int n, int m)
{
    return (n * m);
}
int Div(int n, int m)
{
    return (n / m);
}

vector<FP *> v{Add, Subtr, Mult, Div};

int main()
{
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << (*i)(2, 2) << endl;
    return 0;
}