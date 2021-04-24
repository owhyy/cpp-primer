#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    string in, prev_w;
    int n = 0;
    while (cin >> in && !in.empty())
    {

        if (!isupper(in[0]))
        {
            prev_w = "";
            continue;
        }
        if (in == prev_w)
            break;
        prev_w=in;
    }
    return 0;
}