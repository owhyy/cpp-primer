#ifndef __TEXT_QUERY
#define __TEXT_QUERY

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// forward declaration, in order to be able to use it to define functions and
// members of "QueryResult" type
class QueryResult;

class TextQuery {
public:
  // number of the line
  using line_no = std::vector<std::string>::size_type;
  // constructor, takes ifstream
  TextQuery(std::ifstream &);
  // query function that is going to return the QueryResult containing the
  // set<word, line numbe>, number of occurences and the number of the line
  QueryResult query(const std::string &) const;

private:
  // pointer to vector where every object is a line from the file
  std::shared_ptr<std::vector<std::string>> file;
  // map from string to pointer to set of every word's line number
  std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
  // function that will print to screen
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  // constructor initializing data members
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f) {}

private:
  // word for which we search
  std::string sought;
  // pointer to set of line numbers, shared with TextQuery
  std::shared_ptr<std::set<TextQuery::line_no>> lines;
  // pointer to vector of lines, shared with TextQuery
  std::shared_ptr<std::vector<std::string>> file;
};

// function declaration
void run_queries(std::ifstream &infile);
std::string make_plural(const std::string &sing, uint n);

#endif // __TEXT_QUERY
