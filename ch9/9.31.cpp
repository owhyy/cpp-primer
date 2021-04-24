#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <forward_list>
using namespace std;
using std::string;
using std::vector;

int main()
{
    vector<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto cur = data.begin(); cur != data.end(); ++cur)
    {
        if (*cur % 2)
        {
            cur = data.insert(cur, *cur);
            ++cur;
        }
    }
    for (auto i : data)
        cout << i << " ";

    return 0;
}