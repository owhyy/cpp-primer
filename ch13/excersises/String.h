
#include <algorithm>
#include <memory>
#include <new>
#include <string>
#include <utility>

class String {
public:
  String() : first_character(nullptr), last_character(nullptr), cap(nullptr) {}
  String(const char *);
  String(const String &);
  String &operator=(const String &);
  ~String();

  char *begin() const { return first_character; }
  char *end() const { return last_character; }

  char &operator[](size_t n) { return *(first_character + n); }
  const char &operator[](size_t n) const { return *(first_character + n); }

  size_t size() const { return last_character - first_character; }

private:
  std::allocator<char> alloc;

  inline void free();
  void reallocate();
  void check_if_in_order();
  std::pair<char *, char *> allocate_n_chars(const char *b, const char *e);

  char *first_character;
  char *last_character;
  char *cap;
};

void String::free() {
  if (first_character) {
    std::for_each(first_character, last_character,
                  [this](char &c) { alloc.destroy(&c); });
    alloc.deallocate(first_character, cap - first_character);
  }
}
