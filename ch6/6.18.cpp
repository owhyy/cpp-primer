#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
 
using namespace std;
using std::vector;
using std::string;
 
struct matrix
{
    int n;
};
int count(const string &, char);
vector<int> vec(10);
bool compare(matrix *, matrix * );
vector<int>::iterator change_val(int, vector<int>::iterator);
int main()
{
    count("abcda", 'a');
    return 0;
}