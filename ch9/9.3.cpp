#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <list>
using namespace std;
using std::string;
using std::vector;

int main()
{
    list<const char *> cstring = {"ana", "are", "emer"};
    vector<string> strings = {"she", "loves", "you"};

    strings.assign(cstring.begin(), cstring.end());

    for (auto &&i : strings)
    {
        cout << i << " ";
    }

    return 0;
}