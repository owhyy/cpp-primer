#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

void Print(vector<int>::iterator beg, vector<int>::iterator end)
{
    if (beg != end)
    {
        cout<<*beg;
        Print(beg+1, end);
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    Print(begin(v), end(v));
    return 0;
}