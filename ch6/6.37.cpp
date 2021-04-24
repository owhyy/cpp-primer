#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;
using arrT = int[10];
int odd[] = {1, 3, 5, 7};
int (*func(int i))[10];
arrT *func(int i);
auto func(int i) -> int (*)[10];
decltype(odd) *ff(int i);
int main(int argc, char **argv)
{
    return 0;
}