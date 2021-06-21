// fuck this book, no idea why it does not work. will try later maybe but fuck
// this book
#ifndef __QUERY_VERSIONS_H
#define __QUERY_VERSIONS_H

#include "TextQuery.h"

// abstract class
class Query_base {
  // friend in order to allow Query to call private functions
  friend class Query;

protected:
  // use the TextQuery version of line_no (line number)
  using line_no = TextQuery::line_no;
  // protected to allow derived classes to use it
  virtual ~Query_base() = default;

private:
  // returns QueryResult that matches the TextQuery
  virtual QueryResult eval(const TextQuery &) const = 0;
  // returns a string representation of the Query
  virtual std::string rep() const = 0;
};

class Query {
  // each of the operators will create a <...> Query (NotQuery, OrQuery,
  // AndQuery), and return a Query bound to that, using the
  // shared_ptr(Query_base) (Query_base because every of the up-mentioned
  // queries are going to get converted to Query_base) constructor. this is why
  // the operators are friends
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);

public:
  // constructor taking a string, creating a WordQuery and binding q to that
  Query(const std::string &);
  // in order to be able to use it, Query must define its own version of eval
  // and rep
  QueryResult eval(const TextQuery &t) const { return q->eval(t); }
  std::string rep() const { return q->rep(); }

private:
  // private constructor. will be used by
  Query(std::shared_ptr<Query_base> query) : q(query) {}
  // holds pointer to a Query_base

  // 15.32: when the destructor on Query is called, the reference counter will
  // get decremented. if it reaches 0, the shared_ptr's destructor will get
  // called, which will use the Query_base destructor
  // copying a Quote object will create a new
  // object that shares the same pointer to the Query_base as itself assigning
  // to a Query object will just make the rhs object point to the same object as
  // the lhs object.

  // 15.33: neither of the classes have move
  // constructors. Query because it has a shared_ptr<Query_base>, which has no
  // move constructor beacuse it defines the virtal distructor
  // copying and assigning will just copy and assign the corresponding version
  // of the used derived class member by member
  std::shared_ptr<Query_base> q;
};

// concrete class; defines all abstract functions declared in Query_base
class WordQuery : public Query_base {
  // allow Query to use members of this class (the WordQuery constructor)
  friend class Query;
  WordQuery(const std::string &s) : query_word(s) {}
  // perform the query on the word we search for
  QueryResult eval(const TextQuery &tq) const override {
    return tq.query(query_word);
  }
  // print the word which we search for
  std::string rep() const override { return query_word; }
  // word for which to search
  std::string query_word;
};

// class that finds all objects that are not the sought word
class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}
  std::string rep() const override { return "~(" + query.rep() + ")"; }
  QueryResult eval(const TextQuery &) const override;
  Query query;
};

// abstract class, holding data for AndQuery and OrQuery; does not define eval
class BinaryQuery : public Query_base {
protected:
  // constructor: takes a lhs and a rhs query, and a operator
  BinaryQuery(const Query &l, const Query &r, std::string s)
      : lhs(l), rhs(r), opSym(s) {}
  // representation is the lhs representation + the sign + the rhs
  // represenataion (of the sought word of course)
  std::string rep() const {
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
  }

  Query lhs, rhs;
  std::string opSym;
};

class AndQuery : public BinaryQuery {
  // the & operator can be used by Query
  friend Query operator&(const Query &, const Query &);
  // constructor taking a left and a right hand, and creating a BinaryQuery from
  // them and the "&" operator
  AndQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "&") {}
  // concrete class: defines eval
  QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery {
  // the | operator can be used by Query
  friend Query operator|(const Query &, const Query &);
  // constructor taking a left and a right hand, and creating a BinaryQuery from
  // them and the "|" operator
  OrQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "|") {}
  // concrete class: defines eval
  QueryResult eval(const TextQuery &) const;
};

std::ostream &operator<<(std::ostream &os, const Query &query) {
  // rep makes a virtual call through Query_base's pointer to rep, and will use
  // the coresponding version (WordQuery/AndQuery/NotQuery) of rep
  return os << query.rep();
}

// this constructor allocates a WordQuery and makes the shared_ptr<Query_base>
// point to it
inline Query::Query(const std::string &s) : q(new WordQuery(s)) {
  std::cout << "WordQuery constructor called!\n";
}

// this will allocate a NotQuery and will bind it to the Query
inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}
// this will allocate a AndQuery and will bind it to a Query
inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
// this will allocate a OrQuery and will bind it to a Query
inline Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif //__QUERY_VERSIONS_H
