#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    string text("ana are mere");
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() - (end-beg)/2;
    cout<<*mid<<endl;
    return 0;
}