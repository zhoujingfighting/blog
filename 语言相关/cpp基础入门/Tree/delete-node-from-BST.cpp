/**
 * Delete a tree node from BST
 */

#include "tree-node.h"
#include <iostream>
#include <utility>

/// Find the largest node for the given deleted node;
TreeNode<int> *findMaxNode(TreeNode<int> *root) {
  if (!root->right)
    return root;
  return findMaxNode(root->right);
}

/// Judge a node hs only one child
bool hasOneChild(TreeNode<int> *root) {
  if (root->left && !root->right)
    return true;
  else if (root->right && !root->left)
    return true;
  return false;
}

TreeNode<int> *getChild(TreeNode<int> *root) {
  if (root->left)
    return root->left;
  return root->right;
}

/// case1 : No child
/// case2 : one child
/// case3 : 2 childern
///          /        \
///         /          \
///        /            \
///       /              \
///    solution 1      solution 2
/// Find min in right Find max in left
///  copy the value      copy the value
/// delete duplicate    delete duplicate
///  from right-sub       from left-sub
/// Here we decide to use solution2
TreeNode<int> *deleteNodeFromBST(TreeNode<int> *root, int val) {
  if (root == nullptr)
    return root;
  if (val > root->val)
    root->right = deleteNodeFromBST(root->right, val);
  else if (val < root->val)
    root->left = deleteNodeFromBST(root->left, val);
  else {
    // case1 : no child
    if (!root->left && !root->right) {
      delete root;
      root = nullptr;
      return root;
    }// case2 : one child
    else if (!root->left) {
        TreeNode<int>* tmp = root;
        root = root->right;
        delete tmp;
        return root;
    }
    else if (!root->right) {
        TreeNode<int>* tmp = root;
        root = root->left;
        delete tmp;
        return root;
    } else {
        // case 3 : two sub child tree
        TreeNode<int> *MaxNode = findMaxNode(root->left);
        root->val = MaxNode->val;
        TreeNode<int> *left = root->left;
        // delete root->left;
        //delete left;
        //std::cout << left->val << left << std::endl;
        root->left = deleteNodeFromBST(left, MaxNode->val);
        return root;
    }
  }
  return root;
}
