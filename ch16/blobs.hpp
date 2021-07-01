#ifndef BLOBS_H
#define BLOBS_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T> class BlobPtr;
template <typename T> class Blob;

template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

public:
  // type of value
  typedef T value_type;
  // size_type of vector of ype value
  typedef typename std::vector<T>::size_type size_type;

  // constructors
  Blob();
  Blob(std::initializer_list<T> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const T &obj) { data->push_back(obj); }
  void push_back(T &&obj) { data->push_back(std::move(obj)); }
  void pop_back();

  T &back();
  T &back() const;
  T &front();
  T &front() const;

  T &operator[](size_type i);
  T &operator[](size_type i) const;

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};

template <typename T> class BlobPtr {
public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  T &operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  BlobPtr &operator++();
  BlobPtr &operator--();
  BlobPtr operator++(int);
  BlobPtr operator--(int);

private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};
#endif // BLOBS_H
