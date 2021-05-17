#include "Folder.h"
#include "Message.h"

int main() {
  Message m("Hello, World!");
  Folder f;
  m.save(f);
}
