
#include "Folder.h"
void Folder::add_msg(Message *m) { messages.insert(m); }
void Folder::rem_msg(Message *m) { messages.erase(m); }
