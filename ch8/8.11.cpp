#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using std::string;
using std::vector;

struct Customer
{
    string Name = "jack";
    vector<string> PhoneNumbers;
};

int main()
{
    string line, word;
    vector<Customer> people;
    istringstream iso;
    while (getline(cin, line))
    {
        Customer info;
        iso.clear();
        iso.str(line);
        iso >> info.Name;
        while (iso >> word)
            info.PhoneNumbers.push_back(word);
        people.push_back(info);
    }

    for (auto i : people)
        cout << i.Name << endl;
    return 0;
}