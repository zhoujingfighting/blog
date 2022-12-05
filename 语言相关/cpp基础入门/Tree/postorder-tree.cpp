/**
 * @file postorder-tree.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "tree-node.h"
#include <stack>
using namespace std;

/// We define a function to print a tree in post order
void printPostOrderTree(TreeNode *root) {
  // We use stack to do this
  stack<TreeNode *> treeNodes;
  cout << "PostOrder tree is: ";
  TreeNode* last = nullptr;
  // This means traverse is not ended
  while (root || !treeNodes.empty()) {
    if(root) {
        treeNodes.push(root);
        root = root->left;
    } else {
        TreeNode *node = treeNodes.top();
        if(node->right && last != node->right) 
            root = node->right;
        else {
            cout << node->val << " ";
            last = node;
            treeNodes.pop();
        }
    }
  }
  
  cout << endl;
}