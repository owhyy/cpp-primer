#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::ifstream;
using std::map;
using std::set;
using std::string;
using std::vector;

struct TextQuery {
  TextQuery(ifstream &is);
  uint number_of_occurences(const string &sought) const;
  std::multimap<string, int>
      word_with_number; // specific word, and where to find it
  vector<string> lines; // memorates lines; index is line number

private:
};

TextQuery::TextQuery(ifstream &is) {
  string line;
  uint line_number = 0;
  while (getline(is, line)) {
    lines.push_back(line);
    ++line_number;
    std::istringstream ss(line);
    for (string word; ss >> word;) {
      word_with_number.insert(std::make_pair(word, line_number));
    }
  }
}

uint TextQuery::number_of_occurences(const string &sought) const {
  uint number_of_occurences = 0;
  for (const auto &i : word_with_number)
    if (i.first == sought)
      ++number_of_occurences;
  return number_of_occurences;
}

void print(const TextQuery &tq, const string &sought) {
  auto found_word = tq.word_with_number.find(sought);
  vector<size_t> pos;
  for (auto &i : tq.word_with_number)
    if (i.first == sought)
      pos.push_back(i.second);

  int number_of_occurences = tq.number_of_occurences(sought);
  if (found_word != tq.word_with_number.cend()) {
    cout << "word " << sought << " has " << tq.number_of_occurences(sought)
         << (tq.number_of_occurences(sought) == 1 ? " occurence\n"
                                                  : " occurences\n");
    for (int i = 0; i != number_of_occurences; ++i) {
      int nr_line = pos[i];
      cout << "(line " << nr_line << ") " << tq.lines[nr_line - 1] << "\n";
    }
  } else {
    cout << "word not found";
    return;
  }
}

void call_query(std::ifstream &file) {
  TextQuery tq(file);

  while (true) {
    string word;
    cout << "\nEnter word: Press q to quit\n";
    if (!(cin >> word) || word == "q")
      break;
    print(tq, word);
  }
}

int main() {
  ifstream file("query_in.txt");
  call_query(file);
}
