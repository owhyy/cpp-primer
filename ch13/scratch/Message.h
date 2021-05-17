#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Message {
  friend class Folder;

public:
  explicit Message(const std::string &str = "")
      : contents(str) {} // initializes set of pointers to an empty string
  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();
  void save(Folder &);   // adds message to specific folder
  void remove(Folder &); // removes message from specific folder
  void swap(Message &lhs, Message &rhs);

private:
  std::string contents;                 // message body
  std::set<Folder *> folders;           // set of pointers to folder
  void add_to_folders(const Message &); // add message pointer to all folders
  void remove_from_folders(); // remove message pointer from all folders
};
#endif
