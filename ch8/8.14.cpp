#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;
using std::vector;

constexpr int NrLenght = 11;

struct Customer
{
    string Name = "jack";
    vector<string> PhoneNumbers;
};

bool valid(const string &num)
{
    if (num.size() > NrLenght)
        return false;
    for (const auto &i : num)
        if (i < '0' || i > '9')
            return false;
    return true;
}
string format(const string &s)
{
    return s.substr(0, 3) + '-' + s.substr(3, 4) + '-' + s.substr(7, 4);
}
int main()
{
    ifstream in("8.14.in");
    string line, word;
    vector<Customer> people;
    istringstream iso;
    while (getline(in, line))
    {
        Customer info;
        iso.clear();
        iso.str(line);
        iso >> info.Name;
        while (iso >> word)
            info.PhoneNumbers.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.PhoneNumbers)
        {
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            cout << entry.Name << " "
                 << formatted.str() << endl;
        else
            cerr << "input error: " << entry.Name
                 << " invalid number(s) " << badNums.str() << endl;
    }



    return 0;
}