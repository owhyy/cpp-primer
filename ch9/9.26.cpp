#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
using namespace std;
using std::string;
using std::vector;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v(begin(ia), end(ia));
    list<int> l;
    l.assign(v.begin(), v.end());

    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (*it % 2 == 0)
            it = l.erase(it);
    }
    for (auto it = v.begin(); it != v.end(); ++it)
        if (*it % 2 != 0)
            it=v.erase(it);

    for (auto &&i : v)
        cout << i << " ";
    cout<<endl;
    for (auto &&i : l)
        cout << i << " ";
    cout << endl;

    return 0;
}