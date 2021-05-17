#include "Mail.h"

// Message Implementation
Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_folders(m); // adds new message to all folders
}

Message &Message::operator=(const Message &m) {
  remove_from_folders();
  contents = m.contents;
  folders = m.folders;
  add_to_folders(m);

  return *this;
}

Message::~Message() { remove_from_folders(); }

void Message::save(Folder &f) {
  add_folder(
      &f); // adds pointer to adress of folder to message's folder pointer set
  f.add_message(
      this); // adds message pointer to folder (how does it become pointer tho?)
}

void Message::remove(Folder &f) {
  remove_folder(
      &f); // removes pointer to folder from message's folder pointer set
  f.remove_message(this); // removes message from folder
}

void swap(Message &lhs, Message &rhs) {
  using std::swap;

  lhs.remove_from_folders();
  rhs.remove_from_folders();

  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);

  lhs.add_to_folders(lhs);
  rhs.add_to_folders(rhs);
}

void Message::add_to_folders(const Message &m) {
  for (auto f : folders)  // for every folder pointer that message has
    f->add_message(this); // add a message pointer to the folder
}

void Message::remove_from_folders() {
  for (auto f : folders)
    f->remove_message(this);
}

// Folder Implementation

Folder::Folder(const Folder &f) : messages(f.messages) { add_messages(f); }

Folder &Folder::operator=(const Folder &f) {
  remove_messages();     // delete all old messages from lhs folder
  messages = f.messages; // copy from rhs to lhs
  add_messages(f);       // add all messages from rhs to lhs

  return *this; // return lhs
}

Folder::~Folder() { remove_messages(); }

void swap(Folder &lhs, Folder &rhs) {
  using std::swap;

  lhs.remove_messages(); // remove all folder pointers from lhs
  rhs.remove_messages(); // remove all folder pointers from rhs

  swap(lhs.messages, rhs.messages);

  lhs.add_messages(lhs); // add new folder pointers, but lhs is now rhs
  rhs.add_messages(rhs); // add new folder pointers, but rhs is now lhs
}

void Folder::remove_messages() {
  for (auto m : messages) // for every message in folder
    m->remove_folder(
        this); // remove the folder from message's set of folder pointers
}

void Folder::add_messages(const Folder &f) {
  for (auto m : f.messages)
    m->add_folder(this);
}
