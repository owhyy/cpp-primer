#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <deque>
#include <list>
using namespace std;
using std::string;
using std::vector;

void deqsplitter(list<int> &l)
{
    deque<int> even, odd;
    for (auto it = l.cbegin(); it != l.cend(); ++it)
    {
        if (*it % 2 == 0)
            even.push_back(*it);
        else
            odd.push_back(*it);
    }
    for (const auto &i : even)
        cout << i << " ";
}

int main()
{
    // list<int> list;
    // int n;
    // while (cin >> n)
    //     list.push_back(n);
    // deqsplitter(list);

    vector<int> v;
    cout << v[0] << endl;
    cout << v.at(0) << endl;
    cout << v.front() << endl;
    cout << *v.begin() << endl;
    return 0;
}