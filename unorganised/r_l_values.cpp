#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;
using std::vector;
using std::string;
 
void printSum(int n)
{
    cout<<n+n<<endl;
}

int main()
{
    int i = 5;
    printSum(i);
    printSum(2+3);
    return 0;
}