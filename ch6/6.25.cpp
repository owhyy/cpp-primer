#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main(int argc, char **argv)
{
    string s;
    for (auto i = 1; i != argc; ++i)
        s += string(argv[i]) + " ";
    cout<<s<<endl;
    return 0;
}
