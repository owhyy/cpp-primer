#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void stringReplace(string &s, string &oldVal, string &newVal)
{
    vector<string> nv;
    istringstream iss(s);
    for(string q; iss>>q;)
        nv.push_back(q);
    for(auto i = 0; i!=nv.size(); ++i)
    {
        if(nv[i]==oldVal)
            nv[i].replace(i, newVal.size(), newVal);
    }
    for (const auto i : nv)
        cout << i << " ";
}
int main()
{
    string q = "ana are mere";
    string ov = "ana";
    string nv = "mihaela";
    stringReplace(q, ov, nv);
    return 0;
}