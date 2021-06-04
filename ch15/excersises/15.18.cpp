class Base {
public:
  void pub_mem();

protected:
  int prot_mem;

private:
  char priv_mem;
};

struct Pub_Derv : public Base {
  int f() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
  int f1() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
  int f1() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Der_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
  void memfcn(Base &b) { b = *this; }
};

struct Der_from_Private : public Priv_Derv {
  int use_base();

  void memfcn(Base &b) { b = *this; }
  // even though member functions can use the convertion from derived-to-base
  // regardless of how derived inherits from base, here the Base is simply
  // innacessible because the class from which Der_from_Private inherits is
  // inheriting a private version of Base
};

struct Der_from_Protected : public Prot_Derv {
  int use_base();
  void memfcn(Base &b) { b = *this; }
};

int main(int argc, const char **argv) {
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;

  Pub_Derv dd1;
  Priv_Derv dd2;
  Prot_Derv dd3;

  Base *p =
      &d1; // derived to base convertion can happen only with public inheriting
  p = &d2; // here the inheriting is private
  p = &d3; // here it's protected

  p = &dd1; // members and friends dervied from specific class can use
            // derived-to-base convertion only if the the class inherits using
            // either public or protected here it is public

  p = &dd2; // here it's private, so not possible
  p = &dd3; // here it's protected, but the class that derives is also
            // protected, so it's not possible to convert because, as written in
            // the d operations from above, the convertion happens only with
            // public inheriting

  return 0;
}
