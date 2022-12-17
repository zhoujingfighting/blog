/**
 * Delete a tree node from BST
*/

#include "tree-node.h"
#include <iostream>
#include <utility>
/// Find the deleted node position in the root tree
/// And we also need to get parent node information
TreeNode* findNode(TreeNode *root, int val) {
    if(!root)
        return nullptr;
    if(root->val == val)
        return root;
    else if(root->val > val)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

/// Find the largest node for the given deleted node; 
TreeNode *findMaxNode(TreeNode *root) {
	if(!root->right)
		return root;
	return findMaxNode(root->right);
}

/// Judge a node hs only one child
bool hasOneChild(TreeNode* root) {
	if(root->left && !root->right)
		return true;
	else if(root->right && !root->left)
		return true;
	return false;
}

/// case1 : No child
/// case2 : one child
/// case3 : 2 childern \
///          /        \
///         /          \
///        /            \
///       /              \
///    solution 1      solution 2
/// Find min in right Find max in left
///  copt the value      copt the value 
/// delete duplicate    delete duplicate
///  from right-sub       from left-sub
/// Here we decide to use solution2
void deleteNodeFromBST(TreeNode *root, int val) {
	TreeNode* DeletedNode = findNode(root, val);
	if(!DeletedNode) {
		std::printf("Can not find node in the tree which value equals to %d", val);
		return ;
	}
	// Now we find the actual node to be deleted
	// now we need to take into three way thinking
	// case1 : no child
	if(!DeletedNode->left && !DeletedNode->right)
		DeletedNode = nullptr;
	// case2 : one child, left or right ?
	// we do not simply repalce value, but actually remove the nodes!!!
	else if(hasOneChild(DeletedNode)) {
		if(DeletedNode->left)
		 DeletedNode = DeletedNode->left;
		else 
			DeletedNode = DeletedNode->right;
	}
	// case3 : two children
	// Find max
	// Replace , and delete
	TreeNode* MaxNode = findMaxNode(DeletedNode);
	TreeNode* Right = DeletedNode->right;
	TreeNode* Left = DeletedNode->left;
	*DeletedNode = *MaxNode;
}


