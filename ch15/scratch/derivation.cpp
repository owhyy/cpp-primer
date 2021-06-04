
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
  /* char g() { return priv_mem; } */
};

struct Priv_Derv : private Base {
  int f1() { return prot_mem; }
};

struct Der_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
};

struct Der_from_Private : public Priv_Derv {
  int use_base() { return prot_mem; }
};

int main(int argc, const char **argv) {
  Pub_Derv d1;
  Priv_Derv d2;

  d1.pub_mem(); // public inheritance, members are public
  d2.pub_mem(); // private inheritance, members are private
  return 0;
}
