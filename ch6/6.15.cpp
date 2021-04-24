#include <iostream>
#include <vector>
#include <string>
#include <fstream>

inline std::string::size_type FindChar(const std::string &s, char c, std::string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
int main()
{
    std::string::size_type ctr = 0;
    auto index = FindChar("The quick brown fox", 'q', ctr);
    std::cout << index << " " << ctr << std::endl;
    return 0;
}