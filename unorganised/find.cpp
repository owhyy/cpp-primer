
#include <iostream>
#include <string>

using namespace std;
void first_first_off(const string &s) {
  string numeric("0123456789");
  string alpha("AaBbCcDdEeFfGgHhJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
  string::size_type pos = 0;
  cout << "numeric finder:\n";
  while ((pos = s.find_first_of(numeric, pos)) != string::npos) {
    cout << s[pos] << " ";
    ++pos;
  }
  cout << endl;
  cout << "alphabetical finder:\n";
  pos = 0;
  while ((pos = s.find_first_of(alpha, pos)) != string::npos) {
    cout << s[pos] << " ";
    ++pos;
  }
}

void first_not_off(const string &s) {
  string numeric("0123456789");
  string alpha("AaBbCcDdEeFfGgHhJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
  string::size_type pos = 0;
  cout << "aplhabetical finder:\n";
  while ((pos = s.find_first_not_of(numeric, pos)) != string::npos) {
    cout << s[pos] << " ";
    ++pos;
  }
  cout << "\nnumeric finder:\n";
  pos = 0;
  while ((pos = s.find_first_not_of(alpha, pos)) != string::npos) {
    cout << s[pos] << " ";
    ++pos;
  }
}

int main() {
  /* string s("ab2c3d7R4E6"); */
  /* first_first_off(s); */
  /* cout << endl; */
  /* first_not_off(s); */
	string name = ("r2d2");
	string num = ("0123456789");
	cout<<num.find(name);
  	return 0;
}
