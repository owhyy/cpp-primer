#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;
using std::vector;
using std::string;
 
class Entity
{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};
static vector<double> vec(Entity::vecSize);
constexpr double Entity::rate;
vector<double> Entity::vec;
int main()
{
    
    return 0;
}