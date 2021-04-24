#include <cctype>
#include <iostream>
#include <string>
using namespace std;
using std::string;
int main() {
    string s("yessir!! woogh!#!#");
    string a;
    for (string::size_type c = 0; c < s.size(); c++) {
        if (!ispunct(s[c])) a += s[c];
    }
    cout << a << endl;
    return 0;
}
