#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

constexpr bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}

int main()
{
    string s1 = "ana are mere";
    string s2 = "yes";
    cout << isShorter("aa", "a") << endl;
    return 0;
}