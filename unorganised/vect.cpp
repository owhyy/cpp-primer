#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using std::vector;
    void f();
    void f(int, int);
    void f(int);
    void f(double, double = 3.14);
    int calc(char*, char*);
    int calc(char* const, char* const);
int main()
{
    f(2.56, 3.14);
    return 0;
}
