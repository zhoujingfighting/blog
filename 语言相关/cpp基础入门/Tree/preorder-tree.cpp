/**
 * @file inoder-tree.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-12-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "tree-node.h"
#include <stack>
using namespace std;
/// We define a function to print a tree in inOrder
void printPreOrderTree(TreeNode *root) {
  // We use stack to do this
  stack<TreeNode *> treeNodes;
  cout << "PreOrder tree is: ";
  while (true) {
    while (root) {
      cout << root->val << " ";
      treeNodes.push(root);
      root = root->left;
    }
    if (!treeNodes.empty()) {
      if (treeNodes.top()->right) {
        root = treeNodes.top()->right;
      }
      treeNodes.pop();
    } else
      break;
  }
  cout << endl;
}