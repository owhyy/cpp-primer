#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

bool isPref(vector<int> v1, vector<int> v2)
{
    int flag = 0;
    for (auto i = 0; i != v1.size(); ++i)
        if (v1[i] == v2[i])
            flag = 1;
        else
            flag = 0;
    if (flag)
        return true;
    else
        return false;
}
int main()
{
    vector<int> v1{0, 1, 1};
    vector<int> v2{0, 1, 1, 2, 3, 5};
    if (isPref(v1, v2))
        cout << "Is a prefix" << endl;
    else
        cout << "Is not a prefix" << endl;

    return 0;
}