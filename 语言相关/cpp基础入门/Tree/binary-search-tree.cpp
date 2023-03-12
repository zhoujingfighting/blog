
///  Binary search tree
///  for each node in the tree
///  the value of all the nodes in left subtree is lesser
///  or equal to the value of all the nodes in right subtree is greater

#include "tree-node.h"
#include <iostream>

TreeNode<int> *getNewNode(int val) { return new TreeNode<int>(val); }

/// Insert a val into BST
/// We assume no values are equal
TreeNode<int> *insertBST(TreeNode<int> *&root, int val) {
  TreeNode<int> *node = getNewNode(val);
  if (!root) {
    return root = node;
  }
  if (root->val >= val)
    root->left = insertBST(root->left, val);
  else
    root->right = insertBST(root->right, val);
  return root;
}

extern void printPreOrderTree(TreeNode<int> *root);
extern void printInOrderTree(TreeNode<int> *root);
extern void printPostOrderTree(TreeNode<int> *root);
extern void deleteNodeFromBST(TreeNode<int> *root, int val);
extern bool checkvalidBST(TreeNode<int> *root);
extern int findMin(TreeNode<int> *root);
extern int findMax(TreeNode<int> *root);
///                 20
///                /  \
///               10   30
///              /    /  \
///             1    25  40
///                 /  \   \
///                24   26  41
int main() {
  TreeNode<int> *root = getNewNode(20);
  insertBST(root, 30);
  insertBST(root, 10);
  insertBST(root, 25);
  insertBST(root, 26);
  insertBST(root, 40);
  insertBST(root, 1);
  insertBST(root, 24);
  insertBST(root, 41);
  printPreOrderTree(root);
  printInOrderTree(root);
  printPostOrderTree(root);
  std::cout << "The minimum element in this BST is: " << findMin(root)
            << std::endl;
  std::cout << "The maximum element in this BST is: " << findMax(root)
            << std::endl;
  if (checkvalidBST(root))
    std::cout << "This tree is valid BST" << std::endl;
  deleteNodeFromBST(root, 30);
  printPreOrderTree(root);
  deleteNodeFromBST(root, 25);
  printPreOrderTree(root);
  if (checkvalidBST(root))
    std::cout << "This tree is valid BST" << std::endl;
  return 0;
}