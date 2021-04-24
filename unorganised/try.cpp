#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    int i1, i2;
    while (cin >> i1 >> i2)
    {
        try
        {
            if(i2 == 0)
                throw runtime_error("Can't divide by 0");
        }
        catch (runtime_error err)
        {
            cout << err.what()
                 << "Enter a new number"<<endl;
            cin>>i1>>i2;
            if(!cin || i2==0)
                break;
        }
    }
    cout<<i1/i2<<endl;
    return 0;
}