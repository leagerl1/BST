#include "BST.h"
#include <cmath>

using namespace std;

BST:: BST(){
  root = nullptr;
}

void BST:: insert(int data){
  insert_helper(data,&root);
}

void BST:: insert_helper(int data, BinNode** root){
  BinNode* newNode = new BinNode;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->data = data;
  if(*root == nullptr){
    *root =  newNode;
  }
  else if(data < (*root)->data){
    insert_helper(data,&((*root)->left));
  }
  else if(data > (*root)->data){
    insert_helper(data,&((*root)->right));
  }
  else{
    cerr << "INVALID ENTRY: No duplicates allowed." << endl;
  }
}

void BST:: in_order(){
  in_order_helper(root);
  cout << endl;
}

void BST:: in_order_helper(BinNode* root){
  if(root != nullptr){
    in_order_helper(root->left);
    cout << root->data << ", " ;
    in_order_helper(root->right);
  }
}

void BST:: pre_order(){
    pre_order_helper(root);
    cout << endl;
}

void BST:: pre_order_helper(BinNode* root){
    if(root != nullptr){
        cout << root->data << ", " ;
        pre_order_helper(root->left);
        pre_order_helper(root->right);
    }
}

void BST:: post_order(){
    post_order_helper(root);
    cout << endl;
}

void BST:: post_order_helper(BinNode* root){
    if(root != nullptr){
        post_order_helper(root->left);
        post_order_helper(root->right);
        cout << root->data << ", " ;
    }
}


bool BST:: search_helper(int num, BinNode* root){
  if(root == nullptr){
    cerr << "NOT FOUND" << endl;
    return false;
  }
  else if(root->data == num){
    cerr << "FOUND" << endl;
    return true;
  }
  else{
    if(num < root->data){
      search_helper(num, root->left);
    }
    else{
      search_helper(num, root->right);
    }
  }
}

bool BST:: search(int num){
  search_helper(num, root);
}

bool BST:: isBalanced_helper(BinNode* root){
  if(root!=nullptr){
    int leftHeight = 0;
    int rightHeight = 0;
    BinNode* current = root;
    while(current->left != nullptr){
      leftHeight++;
      current = current->left;
    }
    current = root;
    while(current->right != nullptr){
      rightHeight++;
      current = current->right;
    }
    return (abs(rightHeight-leftHeight <= 1));
  }
  return  isBalanced_helper(root->right) && isBalanced_helper(root->left);
}

bool BST:: isBalanced(){
  if(isBalanced_helper(root)){
    cerr << "BALANCED" << endl;
  }
  else{
    cerr << "UNBALANCED" << endl;
  }
}

void BST:: heightPrinter_helper(BinNode* root, int startHeight){
  if(root != nullptr){
    int leftHeight = startHeight;
    int rightHeight = startHeight++;
    BinNode* current = root;
    while(current->left != nullptr){
      lists[leftHeight].push_back(current->data);
      current = current->left;
      leftHeight++;
    } 
    lists[leftHeight].push_back(current->data);
    if(root->right != nullptr){
      current = root->right;
      while(current->right != nullptr){
	lists[rightHeight].push_back(current->data);
	current = current->right;
	rightHeight++;
      }
      lists[rightHeight].push_back(current->data);
    }
    heightPrinter_helper(root->left, startHeight++);
    heightPrinter_helper(root->right, startHeight++);
  }
}

void BST:: heightPrinter(){
  heightPrinter_helper(root, 0);
  for(int i = 0; i < 5; i++){
    cout << "[" << i << "]: ";
    for(int j = 0; j < lists[i].size(); j++){
      cout << lists[i][j] << ", ";
    }
    cout << endl;
  }
}
