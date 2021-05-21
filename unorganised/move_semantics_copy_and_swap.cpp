
#include <algorithm>
#include <cstddef>
class X {

public:
  friend void swap(X &, X &);
  X();
  X(std::size_t sz) : data(new int[sz]()), size(sz) {}
  X(X &&);
  X(const X &);
  X &operator=(X);
  ~X() { delete[] data; };

private:
  int *data;
  size_t size;
};

void swap(
    X &other,
    X &that) { // friend swap function, swaps only pointers, not whole objects

  using std::swap;

  swap(other.data, that.data);
  swap(other.size, that.size);
}

X::X(X &&other) : X() {
  swap(*this, other);
} // move constructor, initialize this using default constructor

X &X::operator=(X other) { // copy-and-swap on both, rvalues and lvalues
  swap(*this, other);
  return *this;
}

X::X(const X &other) : size(other.size), data(other.data) {
  std::copy(other.data, other.data + size, data);
}
