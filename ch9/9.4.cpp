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
    list<int> l1{1, 3, 5, 7, 9};
    vector<int> v1(2, 3);
    v1.assign(3, 6);
    vector<int> v2{1, 3, 5, 7, 9};
    cout << (v1 == v2);
    return 0;
}