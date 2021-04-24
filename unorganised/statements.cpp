#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

int main()
{
    unsigned ffCnt, flCnt, fiCnt, spCnt, tabCnt, nlCnt, aCnt, eCnt, iCnt, oCnt, uCnt;
    ffCnt = flCnt = fiCnt = spCnt = spCnt = tabCnt = nlCnt = aCnt = eCnt = iCnt = oCnt = uCnt = 0;
    char input, prevch = '\0';
    while (cin>>noskipws>>input)
    {
        switch (input)
        {
        case 'a':
            ++aCnt;
            break;
        case 'A':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;
        case 'E':
            ++eCnt;
            break;
        case 'i':
            if (prevch == 'f')
                ++fiCnt;
            else
                ++iCnt;
            break;
        case 'I':
            ++iCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        case 'O':
            ++oCnt;
            break;
        case 'u':
            ++uCnt;
            break;
        case 'U':
            ++uCnt;
            break;
        case ' ':
            ++spCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++nlCnt;
            break;
        case 'f':
            if (prevch == 'f')
                ++ffCnt;
            break;
        case 'l':
            if (prevch == 'f')
                ++flCnt;
            break;
        }
    prevch = input;

    }
    cout << "There are " << aCnt << " a vowels, \n"
         << "There are " << eCnt << " e vowels, \n"
         << "There are " << iCnt << " i vowels, \n"
         << "There are " << oCnt << " o vowels, \n"
         << "There are " << uCnt << " u vowels. \n"
         << "There are " << tabCnt << " tabs, \n"
         << "There are " << spCnt << " spaces, \n"
         << "There are " << nlCnt << " newlines.\n"
         << "There are " << ffCnt << " 'ff' occurences,\n"
         << "There are " << flCnt << " 'fl' occurences, \n"
         << "There are " << fiCnt << " 'fi' occurences." << endl;
    return 0;
}