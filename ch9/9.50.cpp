#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
  Date() = default;
  Date(const string &date) {
    string d, m, y, D(date);
    size_t found = D.find_first_of("/");
    uint uy, um, ud;
    while (found != std::string::npos) {
      D[found] = ' ';
      found = D.find_first_of("/", found + 1);
    }
    for (auto it = D.begin(); it != D.end(); ++it)
      if (ispunct(*it))
        *it = ' ';
    istringstream iss(D);
    iss >> m;
    iss >> d;
    iss >> y;
    vector<string> smonthlong{
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December",
        "Jan",     "Feb",      "Mar",       "Apr",     "May",      "Jun",
        "Jul",     "Aug",      "Sept",      "Oct",     "Nov",      "Dec"};
    for (auto i = 0; i != smonthlong.size(); ++i) {
      if (smonthlong[i] == m) {
        if (i < 12) {
          this->Month = i + 1;
        } else {
          this->Month = i - 11;
        }
      }
    }
    this->Day = stol(d);
    this->Year = stol(y);
  };
  void print() {
    cout << this->Month << " " << '\t' << this->Day << '\t' << this->Year
         << endl;
  }

private:
  unsigned Year, Month, Day;
  vector<int> years;
  vector<int> imonths;
  vector<int> days;
};
int main() {
  Date d1("Feb, 13, 2004");
  d1.print();
  return 0;
}
