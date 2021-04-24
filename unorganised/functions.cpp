#include <iostream>
#include <vector>
#include <string>
#include "Chapter6.h"
using namespace std;
using std::string;
using std::vector;


int main()
{
    F(4);
    F(4);
    F(4);
    return 0;
}

int Fact(int x)
{
    if (x == 0)
        return 1;
    else
    {
        return x * Fact(x - 1);
    }
}
int FactFromCin()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n == 0)
        return 1;
    else
        return Fact(n);
}
int Abs(int x)
{
    if (x > 0)
        return x;
    else if (x == 0)
        return 0;
    else
        return -x;
}
void F(int n)
{
    static int b = 0;
    if (b + 1 == 1)
    {
        cout << 0;
        ++b;
    }
    else
    {
        for (int i = 0; i != n; ++i)
            cout << ++b;
    }
}