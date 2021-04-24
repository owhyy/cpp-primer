#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <forward_list>
using namespace std;
using std::string;
using std::vector;

void func(forward_list<string> &fs, const string &s1, const string &s2)
{
    auto curr = fs.begin();
    auto prev = fs.before_begin();
    while (curr != fs.end())
    {
        if (*curr == s1)
            curr = fs.insert_after(curr, s2);
        else
        {
            prev = curr;
            ++curr;

        }
    }
    for (const auto &i : fs)
        cout << i << " ";
}

int main()
{
    forward_list<int> f{1, 2, 3, 4, 5, 6};
    auto curr = f.begin();
    auto prev = f.before_begin();
    forward_list<string> qqqq{"ana", "are", "mere"};
    func(qqqq, "ana", "qqqq");
    // while(curr!=f.end())
    // {
    // if(*curr % 2)
    // curr=f.erase_after(prev);
    // else{
    // prev=curr;
    // ++curr;
    // }
    // }
    return 0;
}