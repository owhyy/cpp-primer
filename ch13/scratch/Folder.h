#ifndef FOLDER_H
#define FOLDER_H
#include "Message.h"
#include <set>
class Folder {
public:
  Folder() = default;
  Folder(std::initializer_list<Message *> m_list) {
    for (auto i : m_list)
      add_msg(i);
  }

  void add_msg(Message *);
  void rem_msg(Message *);

private:
  std::set<Message *> messages;
};

#endif
