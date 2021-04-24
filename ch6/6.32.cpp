#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int &get(int *arry, int index)
{
    return arry[index];
}
vector<int> vec(10);
//???
int main()
{
    // int ia[10];
    // for (int i = 0; i != 10; ++i)
    // get(ia, i) = i;
    // for (auto i : ia)
    // cout << i << " ";
    const int &r = 2 + 5;
    cout << r;
    return 0;
}