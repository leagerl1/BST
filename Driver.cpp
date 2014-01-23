#include "BST.h"

using namespace std;

int main(){
  BST tree;
  tree.insert(32);
  tree.insert(45);
  tree.insert(15);
  tree.insert(66);
  tree.insert(76);
  tree.insert(3);
  tree.insert(24);
  tree.insert(18);
  tree.insert(55);
  tree.insert(60);
  tree.insert(18);
  tree.in_order();
  tree.pre_order();
  tree.post_order();
  tree.search(15);
  tree.search(100);
  tree.search(76);
  tree.isBalanced();
  tree.heightPrinter();
}
