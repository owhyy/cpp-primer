#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using namespace std;

int main()
{
    //1
    unsigned n = 0;
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    for (auto it = v1.cbegin(); it != v1.cend(); ++it)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v1 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v2.cbegin(); it != v2.cend(); it++)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v2 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v3.cbegin(); it != v3.cend(); it++)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v3 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v4.cbegin(); it != v4.cend(); ++it)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v4 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v5.cbegin(); it != v5.cend(); ++it)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v5 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v6.cbegin(); it != v6.cend(); ++it)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v6 : " << n << " elements" << endl;
    n = 0;
    for (auto it = v7.cbegin(); it != v7.cend(); ++it)
    {
        n++;
        cout << *it << " ";
    }
    cout << endl
         << "v7 : " << n << " elements" << endl;
    n = 0;
    //2
    string str = "The quick brown fox\njumps over the lazy dog";
    for (auto it = str.begin(); it != str.end() && *it != '\n'; ++it)
        *it = toupper(*it);
    cout << str << endl;
    //3
    vector<int> vasile(10);
    vasile[0] = 3;
    vasile[1] = 9;
    vasile[2] = 32;
    vasile[3] = 11;
    vasile[4] = 2;
    vasile[5] = 9;
    vasile[6] = 31;
    vasile[7] = 8;
    vasile[8] = 2;
    vasile[9] = 21;

    for (auto it = vasile.begin(); it != vasile.end(); it++)
        *it *= 2;
    for (const auto i : vasile)
        cout << i << " ";
    //4
    unsigned suma_adj = 0, suma_f_l = 0;
    vector<int> andrei{8, 3, 9, 11, 0, 2};
    cout << endl
         << "Sums of adjanced pairs : "
         << endl;
    for (auto it = andrei.begin(); it != andrei.end() - 1; it++)
        cout << *it + *(it + 1) << " ";
    auto beg = andrei.begin();
    auto end = andrei.end() - 1;
    cout << endl
         << "Sums of first and last element, then second first and second last and so on : "
         << endl;
    for(; end > beg; ++beg, --end)

    cout << endl;
    //5

    
    return 0;
}