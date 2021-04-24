#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using std::string;
using std::vector;
string asc("df");
string desc("pg");

bool is_asc_desc(const string &s)
{
    if (s.find_first_of(asc) != string::npos || (s.find_first_of(desc)) != string::npos)
        return 1;
    return 0;
}
int main()
{
    string word;
    vector<string> sent;
    vector<string> sv;
    ifstream in("9.49.in");
    while (in.good())
    {
        string::size_type pos = 0;
        in >> word;
        if (!is_asc_desc(word))
            sent.push_back(word);
    }
    string longest = sent[0];
    for (auto i = 0; i != sent.size(); ++i)
        if (sent[i].size() > longest.size())
            longest = sent[i];
    cout << longest;
    return 0;
}
