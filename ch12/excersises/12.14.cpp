
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct destination {};

struct connection {
  connection() {}
};

connection connect(destination *);
void disconnect(connection);
void end_connection(connection *p) { disconnect(*p); }
void f(destination &d) {
  connection c = connect(&d);
  std::unique_ptr<connection, decltype(end_connection) *> p(&c, end_connection);
}
int main() {}
