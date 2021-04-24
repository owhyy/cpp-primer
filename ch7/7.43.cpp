#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

class NoDefault
{   
public:
    NoDefault(int);
};
class C
{   
public:
    C() = default;
    NoDefault c;
};

int main()
{
    vector<C> vec(10);
    return 0;
}

