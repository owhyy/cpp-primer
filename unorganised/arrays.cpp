#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    vector<int> v(10);
    for (int i = 0; i != v.size(); ++i)
        v[i] = i;

    // constexpr size_t array_size = 10;
    // int ia[array_size];
    // for (size_t ix = 0; ix < array_size; ++ix)
    //     ia[ix] = ix;

    // int cia[array_size];
    // for (size_t cix = 0; cix < array_size; ++cix)
    //     cia[cix] = ia[cix];

    // for (auto &&i : cia)
    //     cout << i << " ";

    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt]; // 12 uninitialized elements
    // for each row
    for (size_t i = 0; i != rowCnt; ++i)
    {
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j)
        {
            // assign the element's positional index as its value
            ia[i][j] = i * colCnt + j;
        }
    }
    for (const auto &row : ia)
        for (const auto col : row)
            cout << col << endl;

    int xa[3][4] = {3, 2, 1, 4, 5, 6, 7, 8, 2, 4, 6, 8};
    int(*p)[4] = xa;
    p = &xa[2];
    for (auto p = xa; p != xa + 3; ++p)
    {
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    return 0;
}