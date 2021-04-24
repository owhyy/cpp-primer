#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    string s1;
    string s2;
    do
    {
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
            if (s1.size() > s2.size())
                cout << "the first string is bigger" << endl;
            else
                cout << "the second string is bigger" << endl;
        else if (!s1.empty()&&!s2.empty())
            cout << "the strings are equal" << endl;
    } while (cin);

    return 0;
}