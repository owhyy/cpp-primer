#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}

int main()
{
    string s1 = "ana are mere";
    string s2 = "yes";
    cout << isShorter(s1, s2) << endl;
    return 0;
}