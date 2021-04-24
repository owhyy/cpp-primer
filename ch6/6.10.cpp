#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

inline void Swap(int *x, int *y) { swap(*x, *y); }

int main() {
  int n = 5, m = 9;
  cout << n << " " << m << endl;
  Swap(&n, &m);
  cout << n << " " << m << endl;
  return 0;
}
