#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using std::string;
using std::vector;

istream &read(istream &is)
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
    string line;
    getline(cin, line);
    istringstream iss(line);
    read(iss);    
    return 0;
}