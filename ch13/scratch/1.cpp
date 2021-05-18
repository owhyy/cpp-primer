
class Foo {
public:
  Foo();
  Foo(const Foo &);
  Foo &operator=(const Foo &);
  ~Foo();
};

struct NoCopy {
  NoCopy() = default;
  NoCopy(const NoCopy &) = delete;
  NoCopy &operator=(const NoCopy &) = delete;
  ~NoCopy() = default;
};

struct NoDtor {
  NoDtor() = default;
  ~NoDtor() = delete;
};
/* NoDtor n; */
/* NoDtor *nd = new NoDtor(); */
