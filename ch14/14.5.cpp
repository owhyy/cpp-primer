#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::vector;

class Object {
  friend std::istream &operator>>(std::istream &, Object &);
  friend std::ostream &operator<<(std::ostream &, const Object &);

public:
  Object(string sh, string cl, int he, int wi, int wg)
      : shape(sh), color(cl), height(he), width(wi), weight(wg) {}
  Object() : Object("", "", 0, 0, 0) {}
  Object(const string &sh) : Object(sh, "", 0, 0, 0) {}
  Object(const string &sh, const string &cl) : Object(sh, cl, 0, 0, 0) {}
  Object(int he, int wi, int wg) : Object("", "", he, wi, wg) {}
  Object(int he) : Object("", "", he, 0, 0) {}
  string Shape() const { return shape; }
  string Color() const { return color; }
  int Height() const { return height; }
  int Width() const { return width; }
  int Weight() const { return weight; }

  inline Object &operator=(const std::string &);

  Object &operator++() {
    height++;
    width++;
    weight++;
    return *this;
  }

  Object &operator+=(const Object &rhs) {
    height += rhs.height;
    width += rhs.width;
    weight += rhs.weight;
    return *this;
  }

private:
  string shape;
  string color;
  int height = 0;
  int width = 0;
  int weight = 0;
};

Object operator+(Object lhs, const Object &rhs) {
  lhs += rhs;
  return lhs;
}

std::istream &operator>>(std::istream &is, Object &sd) {
  is >> sd.shape >> sd.color >> sd.height >> sd.width >> sd.weight;
  if (!is)
    sd = Object();
  return is;
}

std::ostream &operator<<(std::ostream &os, const Object &sd) {
  os << sd.shape << sd.color << sd.height << sd.width << sd.weight;
  return os;
}

bool operator==(const Object &lhs, const Object &rhs) {
  if (lhs.Shape() == rhs.Shape() && lhs.Color() == rhs.Color() &&
      lhs.Height() == rhs.Height() && lhs.Width() == rhs.Width() &&
      lhs.Weight() == rhs.Weight())
    return true;
  return false;
}

bool operator!=(const Object &lhs, const Object &rhs) { return !(lhs == rhs); }
inline Object &Object::operator=(const std::string &s) {
  shape = s;
  return *this;
}
int main() { return 0; }
