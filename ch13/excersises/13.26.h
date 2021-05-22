#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
using std::string;
using std::vector;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
  using size_type = vector<string>::size_type;
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

  StrBlob(const StrBlob &);
  StrBlob &operator=(const StrBlob &);
  // no destructor cuz smartptr have their own

  string &operator[](std::size_t index) { return data->at(index); }
  const string &operator[](std::size_t index) const { return data->at(index); }

  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr cbegin();
  ConstStrBlobPtr cend();

  StrBlob() : data(std::make_shared<vector<string>>()) {}
  StrBlob(std::initializer_list<string> il)
      : data(std::make_shared<vector<string>>(il)) {}

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  std::shared_ptr<vector<string>> Data() const { return data; }

  void push_back(const string &t) { data->push_back(t); }
  void pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
  }

  std::string &front() {
    check(0, "front on empty StrBlob");
    return data->front();
  }

  std::string &back() {
    check(0, "back on empty StrBlob");
    return data->back();
  }

  const std::string &front() const {
    check(0, "front on empty StrBlob");
    return data->front();
  }
  const std::string &back() const {
    check(0, "back on empty StrBlob");
    return data->back();
  }

private:
  void check(size_type i, const string &msg) const {
    if (i >= data->size())
      throw std::out_of_range(msg);
  }
  std::shared_ptr<vector<string>> data;
};

class StrBlobPtr {
public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
  bool operator==(const StrBlobPtr &p) { return p.curr == curr; }
  string &operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  string *operator->() const { return &this->operator*(); }
  StrBlobPtr &operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }
  StrBlobPtr &operator--() {
    --curr;
    check(-1, "increment past end of StrBlobPtr");
    return *this;
  }
  StrBlobPtr operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
  }
  StrBlobPtr operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
  }

  StrBlobPtr &operator+(size_t n);
  StrBlobPtr &operator-(size_t n);

  StrBlobPtr &operator+=(size_t n);
  StrBlobPtr &operator-=(size_t n);

  size_t size() const { return curr; }
  string &operator[](std::size_t index) {
    auto p = check(index, "dereference out of range");
    return (*p)[index];
  }
  const string &operator[](std::size_t index) const {
    auto p = check(index, "dereference out of range");
    return (*p)[index];
  }

private:
  std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
  std::weak_ptr<vector<string>> wptr;
  size_t curr;
};

class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }
  bool operator==(const ConstStrBlobPtr &p) { return p.curr == curr; }
  const string *operator->() const { return &this->operator*(); }
  const string &operator*() const {
    const auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  ConstStrBlobPtr &incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  }
  string &operator[](std::size_t index) {
    auto p = check(index, "dereference out of range");
    return (*p)[index];
  }
  const string &operator[](std::size_t index) const {
    auto p = check(index, "dereference out of range");
    return (*p)[index];
  }

private:
  const std::shared_ptr<vector<string>> check(size_t i,
                                              const string &msg) const {
    const auto ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
  const std::weak_ptr<vector<string>> wptr;
  size_t curr;
};

struct PointerToStrBlobPtr {
  StrBlobPtr *p;
  StrBlobPtr *operator->() const { return p; }
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.Data() == rhs.Data();
}
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs == rhs;
}
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
  return lhs == rhs;
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return lhs.size() < rhs.size();
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
  return rhs.size() < lhs.size();
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs.size() > rhs.size());
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs.size() < rhs.size());
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.size() < rhs.size();
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return rhs.size() < lhs.size();
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs.size() > rhs.size());
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs.size() < rhs.size());
}
StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
  curr += n;
  check(curr, "index out of range");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
  curr -= n;
  check(curr, "index out of range");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator+(size_t n) {
  StrBlobPtr ret = *this;
  ret += n;
  return ret;
}
StrBlobPtr &StrBlobPtr::operator-(size_t n) {
  StrBlobPtr ret = *this;
  ret -= n;
  return ret;
}
