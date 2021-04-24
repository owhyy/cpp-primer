#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;
using std::vector;
using std::string;
 
void SumInitList(initializer_list<int> ls)
{
    int sum = 0;
    // for(auto it = ls.begin(); it!=ls.end(); ++it)
    for(auto &i : ls)
        sum+=i;
    cout<<"The sum of elements: "<<sum<<endl;
}

int main()
{
    SumInitList({3,4,5,8});
    return 0;
}