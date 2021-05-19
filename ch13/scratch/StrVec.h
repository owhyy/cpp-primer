
#include <memory>
#include <new>
#include <string>

class StrVec {
public:
  StrVec() : elements(nullptr), last_element(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> sl);
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);

  StrVec &operator=(StrVec &&) noexcept;
  StrVec(StrVec &&) noexcept;
  ~StrVec();

  void push_back(const std::string &s) {
    check_n_allocate();
    alloc.construct(last_element++, s);
  }

  void push_back(std::string &&s) {
    check_n_allocate();
    alloc.construct(last_element++, std::move(s));
  }

  std::string *begin() const { return elements; }
  std::string *end() const { return last_element; }

  size_t size() const { return last_element - elements; }
  size_t capacity() const { return cap - elements; }

  void resize(int n);
  void resize(int n, const std::string &);
  void reserve(int n);

private:
  std::string *elements;
  std::string *last_element;
  std::string *cap;

  std::allocator<std::string> alloc;
  std::pair<std::string *, std::string *> allocate_n_copy(const std::string *b,
                                                          const std::string *e);
  void reallocate();
  void free();
  void check_n_allocate() {
    if (size() == capacity())
      reallocate();
  }
};
