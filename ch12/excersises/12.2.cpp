#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob(std::initializer_list<std::string> il);
  StrBlob();
  bool empty() const { return data->empty(); }
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  int size() const { return data->size(); }
  std::string &front() const;
  std::string &back() const;
  std::string &front();
  std::string &back();

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &m) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

std::string &StrBlob::front() {
  check(0, "front on empty Strblob");
  return data->front();
}
std::string &StrBlob::back() {
  check(0, "back on empty Strblob");
  return data->back();
}
std::string &StrBlob::front() const {
  check(0, "front on empty Strblob");
  return data->front();
}
std::string &StrBlob::back() const {
  check(0, "back on empty Strblob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}
void StrBlob::check(size_type i, const std::string &m) const {
  if (data->size() <= i)
    throw std::out_of_range(m);
}

int main() {
  StrBlob b1;
  {
    StrBlob b2 = {"ana", "are", "mere"};
    b1 = b2;
    b2.push_back("about"); // b2 gets destroyed here, so no elements
  }
  std::cout << b1.size();
}
