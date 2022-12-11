
///  Binary search tree
///  for each node in the tree
///  the value of all the nodes in left subtree is lesser
///  or equal to the value of all the nodes in right subtree is greater

#include "tree-node.h"
#include <iostream>

TreeNode *getNewNode(int val) { return new TreeNode(val); }

/// Insert a val into BST
/// We assume no values are equal
TreeNode *insertBST(TreeNode *&root, int val) {
  TreeNode *node = getNewNode(val);
  if (!root) {
    return root = node;
  }
  if (root->val >= val)
    root->left = insertBST(root->left, val);
  else
    root->right = insertBST(root->right, val);
  return root;
}

extern void printPreOrderTree(TreeNode *root);
extern void printInOrderTree(TreeNode *root);
extern void printPostOrderTree(TreeNode *root);
extern int findMin(TreeNode *root);
extern int findMax(TreeNode *root);
///                 20
///                /  \
///               10   30
///              /    /  \
///             1    25  40
///                 /      \
///                24       41
int main() {
  TreeNode *root = getNewNode(20);
  insertBST(root, 30);
  insertBST(root, 10);
  insertBST(root, 25);
  insertBST(root, 40);
  insertBST(root, 1);
  insertBST(root, 24);
  insertBST(root, 41);
  printPreOrderTree(root);
  printInOrderTree(root);
  printPostOrderTree(root);
  std::cout << "The minimum element in this BST is: " << findMin(root) << std::endl;
  std::cout << "The maximum element in this BST is: " << findMax(root) << std::endl;
  return 0;
}