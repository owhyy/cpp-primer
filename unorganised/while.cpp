#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    string word, preword, max_rep_word;
    int cnt = 0, n=0;
    while (cin >> word)
    {
        if (word == preword)
            ++cnt;
        else
        {
            cnt = 1;
            preword = word;
        }
        if (n < cnt)
        {
            n = cnt;
            max_rep_word = preword;
        }
    }
    if(n<=1)
        cout<<"No words were repeated"<<endl;
    else
        cout << "The word " << max_rep_word << " was repeated " << n << " times" << endl;
    return 0;
}