#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main() {
  std::multimap<string, string> authors_and_works;

  authors_and_works.insert({"John Doyle", "The Centaurus"});
  authors_and_works.insert({"Thomas Mann", "The Magic Mountain"});
  authors_and_works.insert({"Haruki Murakami", "Kafka On the Shore"});
  authors_and_works.insert({"Franz Kafka", "The Process"});
  authors_and_works.insert({"Haruki Murakami", "Norwegian Woods"});
  authors_and_works.insert({"Haruki Murakami", "1Q84"});

  string author_to_be_removed;
  cout<<"Enter name of author";
  getline(cin, author_to_be_removed);

  auto found = authors_and_works.find(author_to_be_removed);

  if (found != authors_and_works.end()) {
    if (authors_and_works.count(author_to_be_removed) > 1) {
      cout << "Author found. Choose book:\n\n";
      for (auto it = authors_and_works.lower_bound(author_to_be_removed);
           it != authors_and_works.upper_bound(author_to_be_removed); ++it)
        cout << it->second << "\n";
      string book_to_be_removed;
      getline(cin, book_to_be_removed);
      for (auto it = authors_and_works.lower_bound(author_to_be_removed);
           it != authors_and_works.upper_bound(author_to_be_removed); ++it)
        if (it->second == book_to_be_removed) {
          cout << "Book " << it->second << " deleted\n";
          authors_and_works.erase(it);
          break;
        }
    } else {
      cout << "Book " << found->second << " deleted\n";
      authors_and_works.erase(found);
    }
  } else
    cout << "Author not found";
  
  cout<<"\n\n";
  for(auto &i : authors_and_works) // it is already alphabetically I believe
    cout<<i.first<<' '<<i.second<<'\n';
}
