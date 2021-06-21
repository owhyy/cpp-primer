
#include "TextQuery.h"
using namespace std;

string make_plural(const string &sing, uint n) {
  return (n == 1 ? sing : sing + "s");
}

void run_queries(ifstream &infile) {
  // create a new text query from ifstream
  TextQuery tq(infile);

  // prompt for input and print query result
  while (true) {
    cout << "enter word to search for, or enter q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    // print query result from s
    print(cout, tq.query(s));
  }
}

TextQuery::TextQuery(ifstream &ifs) : file(new vector<string>) {
  string text;
  if (ifs.is_open())
    while (getline(ifs, text)) {
      // add line to vector of lines
      file->push_back(text);
      // current line number
      int n = file->size() - 1;
      // separate line into words
      istringstream line(text);
      string word;
      // while reading words
      while (line >> word) {
        // if word is not already in wm, add it
        // also, lines is a sharedptr reference to wm's line number set
        auto &lines = wm[word];
        // if the pointer to the set is null the first time
        if (!lines)
          // allocate a new set
          lines.reset(new set<line_no>);
        // add the line number of the word
        lines->insert(n);
      }
    }
  else
    return;
}

QueryResult TextQuery::query(const std::string &sought) const {
  // allocate new set
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  // search for the word in the keys of the map
  // use find, as opposed to subscript to avoid creating new objects if object
  // was not found
  auto loc = wm.find(sought);
  // if sought was not found
  if (loc == wm.end())
    // return result with empty number set
    return QueryResult(sought, nodata, file);
  else
    // otherwise return the Query with the word, the set of numbers on which the
    // word is found, and the vector with all the lines
    return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
  // print the number of occurences
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << make_plural("time", qr.lines->size()) << '\n';
  // for every line number in the set
  for (auto num : *qr.lines)
    // print the line number + 1 (in order to avoid confusion),
    // and the content of the line
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << '\n';
  return os;
}
