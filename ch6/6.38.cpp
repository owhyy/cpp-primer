#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;
int odd[] = {1, 3, 5, 7};
int even[] = {0, 2, 4, 6};
decltype(odd) &arrPtr(int i)
{
    return (i % 2) ? odd : even;
}


int main()
{
    int arr[]{2, 3, 2, 9};
    int newarr[4];
    for (int i = 0; i != 4; ++i)
        newarr[i] = *arrPtr(*arr + i);
    for (auto i : newarr)
        cout << i << " ";
    return 0;
}