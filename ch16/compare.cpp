#include <iostream>
template <typename T> T beg(const T &arr) {
  return arr;
}
/* template <typename T> T end(const T &arr) { return arr + sizeof(arr) /
 * arr[0]; } */

int main() {
  int iarr[4] = {9, 13, 24};
  int qq = beg(iarr);
}
