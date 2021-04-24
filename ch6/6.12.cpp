#include <iostream>
#include <vector>
#include <string>
#include <fstream>

inline void Swap(int &x, int &y)
{
    std::swap(x, y);
}

int main()
{
    int a = 4, b = 9;
    Swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}