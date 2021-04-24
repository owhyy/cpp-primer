#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;
class Person
{
public:
    Person() = default;
    Person(const std::string &name, const std::string &adress) : name(name), adress(adress){};
    explicit Person(istream &is) {Read(is, *this);}
    istream &Read(istream &, Person &p);
    ostream &Print(ostream &, const Person &p);

private:
    std::string name, adress;
    std::string RetName() const { return name; };
    std::string RetAdress() const { return adress; };

};

istream &Person::Read(istream &is, Person &p)
{
    is >> p.name >> p.adress;
    return is;
};
ostream &Person::Print(ostream &os, const Person &p)
{
    os << p.name << " " << p.adress;
    return os;
}

int main()
{
    Person p1("John", "Wall Street");

    p1.Print(cout, p1);
    return 0;
}
