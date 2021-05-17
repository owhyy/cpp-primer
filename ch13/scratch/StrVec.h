#include <string>
// memory implementation for a vector-like class
class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  ~StrVec();
  void push_back(const std::string &);
  size_t size() const { return first_free - elements; } // nr of elements in use
  size_t capacity() const {
    return cap - elements;
  } // nr of elements the array can hold
  std::string *begin() const { return elements; } // first element
  std::string *end() const { return first_free; } // last element

private:
  std::allocator<std::string> alloc; // allocates memory used by the
                                     // functions that add elements

  // utilities for copy construct, destructor etc.

  // reallocates StrVec when there is no room to add a new element(when size
  // equals capacity)
  void check_n_allocate() {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> allocate_n_copy(const std::string *,
                                                          const std::string *);
  void free();       // destroy elements and deallocate
  void reallocate(); // get more space and copy elements into it

  std::string *elements;   // first element in array
  std::string *first_free; // first free element(last + 1)
  std::string *cap;        // one past the end of array(max size of array)
};
