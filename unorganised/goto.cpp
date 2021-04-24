#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    int i = 42;
    int *const p = &i;
    *p = 0;
    cout << p << " " << i << endl;
    return 0;
}