#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

void readWord(const string &name, vector<string> &svec)
{
    ifstream in(name);
    while (in.good())
    {
        string tmp;
        in >> tmp;
        svec.push_back(tmp);
    }
    for (auto &i : svec)
        cout << i << endl;
}
void readLine(const string &name, vector<string> &svec)
{
    ifstream in(name);
    while (in.good())
    {
        string tmp;
        getline(in, tmp);
        svec.push_back(tmp);
    }
    for (auto &i : svec)
        cout << i << endl;
}
int main()
{
    vector<string> vec1;
    vector<string> vec2;
    readLine("files", vec1);
    readWord("files", vec2);
    return 0;
}