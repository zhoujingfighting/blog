
///  Binary search tree
///  for each node in the tree
///  the value of all the nodes in left subtree is lesser
///  or equal to the value of all the nodes in right subtree is greater

#include "tree-node.h"

TreeNode *getNewNode(int val) { return new TreeNode(val); }

/// Insert a val into BST
/// We assume no values are equal
void insertBST(TreeNode *&root, int val) {
  TreeNode *node = getNewNode(val);
  if (!root) {
    root = node;
    return;
  } else if (!root->left && !root->right) {
    if (root->val >= val) {
      root->left = node;
      return;
    } else {
      root->right = node;
      return;
    }
  } else {
    if (root->val >= val)
      return insertBST(root->left, val);
    else
      return insertBST(root->right, val);
  }
}

extern void printPreOrderTree(TreeNode *root);
extern void printInOrderTree(TreeNode *root);
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
  return 0;
}