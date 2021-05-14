#include <cstring>
#include <iostream>
#include <new>
#include <string>
int main() {
  std::string s1{"Ana"};
  std::string s2{" are mere"};
  std::string s3 = s1 + s2;

  char str_literal_1[4] = "Ana";
  char str_literal_2[12] = " are mere";
  char *str_literal_3 = new char[20];
  strcpy(str_literal_3, str_literal_1);
  strcat(str_literal_3, str_literal_2);

  for (auto *i = str_literal_3; i != str_literal_3 + 20; ++i)
    std::cout << *i;

  std::cout << '\n';
  char *arr = new char[s3.size() + 1];
  std::strcpy(arr, s3.c_str());
  for (auto *i = arr; i != arr + s3.size(); ++i)
    std::cout << *i;

  delete[] arr;
  delete[] str_literal_3;
}
