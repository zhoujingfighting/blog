/**
 * Check valid BST
 */

#include "tree-node.h"

/// @brief All the left tree value should be less or equal than root's value
/// @param root the root tree node
/// @param value the value to be compared
/// @return a boolean flag
bool isLefTreeLess(TreeNode<int> *root, int value) {
	if(!root)
		return true;
	if(isLefTreeLess(root->left, value)
		&& isLefTreeLess(root->right, value)
		&& root->val <= value
	)
		return true;
	return false;
}

/// @brief All the right tree value should be greater than root's value
/// @param root the root tree node
/// @param value the value to be compared
/// @return a boolean flag
bool isRightTreeBigger(TreeNode<int> *root, int value) {
		if(!root)
		return true;
	if(isRightTreeBigger(root->left, value)
		&& isRightTreeBigger(root->right, value)
		&& root->val >= value
	)
		return true;
	return false;
}

/// @brief Check a BST tree is valid BST or not
/// @param root the root node
/// @return a boolean flag
bool checkvalidBST(TreeNode<int> *root) {
  if (!root)
    return true;
  if (checkvalidBST(root->left)
		&& checkvalidBST(root->right)
		&& isLefTreeLess(root->left, root->val)
		&&isRightTreeBigger(root->right, root->val))
    return true;
  return false;
}