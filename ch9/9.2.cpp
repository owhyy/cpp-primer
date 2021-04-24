#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <deque>
using namespace std;
using std::string;
using std::vector;

bool check(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    bool flag = 0;
    while (begin != end)
    {
        if (*begin == val)
            flag = 1;
        ++begin;
    }
    return flag;
}

vector<int>::iterator pos(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    while (begin != end)
    {
        if (*begin == val)
            return begin;
        ++begin;
    }
    cout << "String is empty\n";
    return begin;
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    vector<int> v2(v);
    vector<double> v3(v.begin(), v.end());
    vector<int> v4 = {1,2,3,45};
    vector<int> v5(19, 0);
    vector<int> v6(6);

    list<deque<int>> yeahboi;
    // cout << check(v.begin(), v.end(), 33) << '\n';
    auto it = pos(v.begin(), v.end(), 33);
    cout << *it;
    return 0;
}