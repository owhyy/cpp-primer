#include <fstream>
#include <iostream>
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

class QueryResult;
class TextQuery {
public:
  using line_no = vector<string>::size_type;
  TextQuery(ifstream &);
  QueryResult query(const string &) const;

private:
  std::shared_ptr<vector<string>> file; // input

  // map of word to set of lines on which the word appears
  map<string, std::shared_ptr<set<line_no>>> wm;
};

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);
  using line_no = vector<string>::size_type;

public:
  QueryResult(string s, std::shared_ptr<set<line_no>> p,
              std::shared_ptr<vector<string>> f)
      : sought(s), lines(p), file(f) {}
  std::shared_ptr<set<line_no>> begin() const {
    return std::make_shared<set<line_no>>(lines->begin());
  };
  std::shared_ptr<set<line_no>> end() const {
    return std::make_shared<set<line_no>>(lines->end());
  };
  std::shared_ptr<vector<string>> get_file() const { return file; }

private:
  string sought;
  std::shared_ptr<set<line_no>> lines;
  std::shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
  string text;
  while (getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;
    std::istringstream line(text);
    string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines)
        lines.reset(new set<line_no>);
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const string &sought) const {
  static std::shared_ptr<set<line_no>> nodata(new set<line_no>);

  auto loc = wm.find(sought);
  if (loc == wm.end())
    return QueryResult(sought, nodata, file);
  else
    return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << " occurs " << qr.lines->size() << " "
     << (qr.lines->size() == 1 ? "time" : "times") << '\n';
  for (auto num : *qr.lines)
    os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << '\n';
  return os;
}

void runQueries(ifstream &infile) {
  TextQuery tq(infile);

  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s)) << '\n';
  }
}
