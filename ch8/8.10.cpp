#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    vector<string> svec;
    ifstream in("8.10.in");
    while (in.good())
    {
        string line, word;
        getline(in, line);
        istringstream iss(line);
        while(iss>>word)
            svec.push_back(word);
    }


    for (const auto &i : svec)
        cout << i;
    return 0;
}