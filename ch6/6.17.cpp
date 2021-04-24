#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

inline bool ContainsCapLetters(const std::string &s)
{
    for (const auto &i : s)
        return (isupper(i));
    return 0;
}

inline void LettersToLower(std::string &s)
{
    for(auto &i : s)
        i=tolower(i);
}

int main()
{
    std::string sent("RUBBER SOUL");
    std::cout << sent << std::endl;
    LettersToLower(sent);
    std::cout << sent << std::endl;
    std::cout << ContainsCapLetters("anne frank") << std::endl;
    return 0;
}