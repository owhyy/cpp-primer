#include <iostream>
#include <vector>
#include <string>
#include <fstream>

inline int Reset(int &n)
{
    n = 0;
    return n;
}
inline void Reset (std::string::size_type *n)
{
    *n=0;
}
int main()
{
    int tmp = 300;
    Reset(tmp);
    std::cout << tmp << std::endl;
    return 0;
}