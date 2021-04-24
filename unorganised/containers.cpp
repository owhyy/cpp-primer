#include <iostream>
#include <string>
#include <vector>
using namespace std;
string yikes(const string &name, const string &pref, const string &suf)
{
  string ns = name;
  auto bg = ns.begin();
  ns.insert(bg, pref.begin(), pref.end());
  ns.append(suf);
  return ns;
}
string yikes_in_only(const string &name, const string &pref, const string &suf)
{
  string ns = name;
  ns.insert(0, pref);
  ns.insert(ns.size(), suf);
  return ns;
}
int main()
{
  string pf = "Mr ";
  string sf = " the III ";
  string n = "Jack";
  cout<<yikes_in_only(n, pf, sf);

  return 0;
}
