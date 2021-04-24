#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

int main()
{
    int v[5]{
        1,
        2,
        3,
        4,
        5,
    };
    int *p = begin(v);
    // print(begin(v), end(v));
    while (*begin(v) != *end(v))
        cout << ++p << endl;
    return 0;
}