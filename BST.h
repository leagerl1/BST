#include <iostream>
#include <vector>

class BST{
 private:
  struct BinNode{
    int data;
    BinNode* left;
    BinNode* right;
  };

  BinNode* root;
  std::vector<int> lists[5];

  void insert_helper(int data,BinNode** root);
  void in_order_helper(BinNode* root);
  void pre_order_helper(BinNode* root);
  void post_order_helper(BinNode* root);
  bool search_helper(int num, BinNode* root);
  bool isBalanced_helper(BinNode* root);
  void heightPrinter_helper(BinNode* root, int startHeight);

 public:
  BST();
  void insert(int data);
  void in_order();
  void pre_order();
  void post_order();
  bool search(int num);
  bool isBalanced();
  void heightPrinter();
};
