
#include "Message.h"
#include "Folder.h"

// parameter is of type Folder & because:
// 1. you want to operate on the direct version (not on a copy) of Folder
// 2. if it were const, you wouldn't be able to call add_msg, as Folder
// would not be modifiable
void Message::save(Folder &f) {
  folders.insert(&f);
  f.add_msg(this); // folder function
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.rem_msg(this);
}

// function adding message pointer to folder
void Message::add_to_folders(const Message &m) {
  for (auto f : m.folders) // for each folder that holds m
    f->add_msg(this);      // add pointer to m
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_folders(m); // if it were synthisized - it wouldn't add to folder
}

void Message::remove_from_folders() {
  for (auto f : folders) // for each folder pointer in folder
    f->rem_msg(this);    // remove the pointer
}

Message::~Message() { remove_from_folders(); }

Message &Message::operator=(const Message &rhs) {
  remove_from_folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_folders(rhs);
  return *this;
}

void Message::swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders)
    f->rem_msg(&lhs);
  for (auto f : rhs.folders)
    f->rem_msg(&lhs);

  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders)
    f->add_msg(&lhs);
  for (auto f : rhs.folders)
    f->add_msg(&rhs);
}
