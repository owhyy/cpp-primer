#include <string>
#include <vector>

class TreeNode {
public:
  TreeNode();
  TreeNode(const TreeNode &);
  TreeNode &operator=(const TreeNode &);
  ~TreeNode();

private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};
TreeNode::TreeNode()
    : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {
  if (--*count == 0) {
    delete left;
    delete right;
    delete count;
  }
}

TreeNode::TreeNode(const TreeNode &rhs)
    : value(rhs.value), left(rhs.left), right(rhs.right), count(rhs.count) {
  ++*rhs.count;
}

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  ++*rhs.count;
  if (--*count == 0) {
    delete left;
    delete right;
    delete count;
  }
  value = rhs.value;
  left = rhs.left;
  right = rhs.right;
  count = rhs.count;
  return *this;
}

class BinStrTree {
  TreeNode *root;

public:
  BinStrTree() : root(new TreeNode()) {}
  ~BinStrTree();

  BinStrTree(const BinStrTree &rt) : root(new TreeNode(*rt.root)) {}
  BinStrTree &operator=(const BinStrTree &rt);
};
BinStrTree &BinStrTree::operator=(const BinStrTree &rt) {
  auto newp = new TreeNode(*rt.root);
  delete root;
  root = newp;

  return *this;
}

BinStrTree::~BinStrTree() { delete root; }
