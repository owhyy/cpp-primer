#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::string;
using std::vector;

class Object
{
public:
    Object(string sh, string cl, int he, int wi, int wg) : shape(sh), color(cl), height(he), width(wi), weight(wg) {}
    Object() : Object("", "", 0, 0, 0) {}
    Object(const string &sh) : Object(sh, "", 0, 0, 0) {}
    Object(const string &sh, const string &cl) : Object(sh, cl, 0, 0, 0) {}
    Object(const string &cl) : Object("", cl, 0, 0, 0) {}
    Object(int he, int wi, int wg) : Object("", "", he, wi, wg) {}
    Object(int he) : Object("", "", he, 0, 0) {}
    Object(int wi) : Object("", "", 0, wi, 0) {}
    Object(int wg) : Object("", "", 0, 0, wg) {}

private:
    string shape;
    string color;
    int height = 0;
    int width = 0;
    int weight = 0;
};

int main()
{

    return 0;
}