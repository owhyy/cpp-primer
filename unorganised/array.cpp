#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    int flag = 0;
    constexpr size_t size = 5;
    int arr[size] = {0, 1, 2, 3, 4};
    int arr2[size] = {0, 1, 2, 3, 4};
    int *p = arr;
    int *p2 = arr2;
    for (p; p != std::end(arr) && p2 != std::end(arr2); ++p, ++p2)
        if (*p == *p2)
            flag = 1;
        else
            flag = 0;
    if (flag)
        cout << "The arrays are equal" << endl;
    else
        cout << "The arrays are not equal" << endl;
    for (const auto i : arr)
        cout << i << " ";
    cout<<endl;

    vector<int> v1{0, 1, 2, 3, 5};
    vector<int> v2{0, 1, 2, 3, 5};
    bool is = 0;
    for (auto i = 0, j=0; i != v1.size() && j != v2.size(); ++i, ++j)
        if (v1[i] == v2[j])
            is = 1;
        else
            is = 0;
    if (is)
        cout << "Vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;


    return 0;
}