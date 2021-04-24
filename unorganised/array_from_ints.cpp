#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;
using std::vector;
using std::string;
 
int main()
{
    vector<int> v {9,3,4,12,44,2};
    int arr[6];
    for(auto i = 0; i!=v.size(); ++i)
        arr[i]=v[i];
    for(const auto i : arr)
        cout<<i<<" ";
    return 0;
}