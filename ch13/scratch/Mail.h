#pragma once
#include <set>
#include <string>
class Folder;

class Message {
  friend void swap(Message &, Message &);
  friend class Folder;

public:
  explicit Message(const std::string &s = "") : contents(s) {}
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  void save(Folder &);   // adding one message to the folder
  void remove(Folder &); // removing one message from the folder

private:
  std::string contents;
  std::set<Folder *> folders;

  void add_to_folders(
      const Message &);       // adding message to all the folders that have it
  void remove_from_folders(); // removing message from all the folders

  void add_folder(Folder *f) {
    folders.insert(f);
  } // inserts folder into folders
  void remove_folder(Folder *f) {
    folders.erase(f);
  } // removes folder from folders
};
void swap(Message &, Message &);

class Folder {
  friend class Message;
  friend void swap(Folder &lhs, Folder &rhs);

public:
  Folder() = default;
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();

  void swap(Folder &, Folder &);

private:
  std::set<Message *> messages;

  void add_message(Message *m) { messages.insert(m); }   // adds one message
  void remove_message(Message *m) { messages.erase(m); } // removes one message

  void
  add_messages(const Folder &); // adds all messages to from folder to folder
  void remove_messages();       // removes all messages from current folder
};

void swap(Folder &lhs, Folder &rhs);
