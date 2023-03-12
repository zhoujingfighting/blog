/**
 * find the max and min element in a BST tree
*/

#include "tree-node.h"
int findMin(TreeNode<int>* root) {
    // FIXME: maybe need to pay attention
    // when the root is null
    if(!root->left)
        return root->val;
    return findMin(root->left);
}

int findMax(TreeNode<int>* root) {
    if(!root->right)
        return root->val;
    return findMax(root->right);
}