#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    for (int (&row)[4]: arr)
    {
        for (int col : row)
            cout << col << " ";
        cout << endl;
    }
    for(int (*i)[4] = arr; i!=arr+3; ++i)
    {
        for(int *q=*i; q!=*i+4; ++q)
            cout<<*q<<" ";
        cout<<endl;
    }
    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 4; ++j)
            cout << (arr[i][j])<<" ";
        cout << endl;
    }
    for(int (*i)[4]=begin(arr); i!=end(arr); ++i)
    {
        for(int *j = begin(*i); j!=end(*i); ++j)
            cout<<*j<<" ";
        cout<<endl;
    }
    using arr_type = int[4]; //basically makes arr_type of type array of 4
    for (arr_type *i = arr; i != arr + 3; ++i)
    {
        for (int *x = *i; x != *i + 4; ++x)
            cout << *x << " ";
        cout << endl;
    }
    for(arr_type *i=begin(arr); i!=end(arr); ++i)
    {
        for(int *j = begin(*i); j!=end(*i); ++j)
            cout<<*j<<" ";
        cout<<endl;
    }
    for (arr_type &p : arr)
    {
        for (int col : p)
            cout << col << " ";
        cout << endl;
    }
    for (const auto &i : arr)
    {
        for (const auto col : i)
            cout << col << " ";
        cout << endl;
    }
    for(auto i = arr; i!=arr+3; ++i)
    {
        for(auto j = *i; j!=*i+4; ++j)
            cout<<*j<<" ";
        cout<<endl;
    }
    for(auto i = begin(arr); i!=end(arr); ++i)
    {
        for(auto q = begin(*i); q!=end(*i); ++q)
            cout<<*q<<" ";
        cout<<endl;
    }
    return 0;
}