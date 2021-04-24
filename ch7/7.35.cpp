#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

// typedef string Type;
// Type initVal();
// class Excersise {
// public:
//     typedef double Type;
//     Type setVal(Type);
//     Type initVal();
// private:
//     int val;
// };

struct x
{
    x(int i, int j) : base(i), rem(i % j) {}
    int rem, base;
};

// Excersise::Type Excersise::setVal(Type param)
// {
//     val = param + initVal();
//     return val;
// }
int main()
{
    x j(8, 3);
    cout << j.rem << " " << j.base << endl;
    return 0;
}