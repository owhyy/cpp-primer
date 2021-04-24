#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

istream &function(istream &is)
{
    string txt;
    while (!is.eof())
    {
        is >> txt;
        cout << txt << endl;
    }
    is.clear();
    return is;
}
int main()
{
    function(cin);
    return 0;
}