/**
 * @file tree-node.h
 * @author Zhou Jing (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */

/// @brief Tree applications :
/// 1 : storing the data ==>> file system, hierarchical data
/// 2 : organize data : quick search,insertion,deletion ==>> binary search trees
/// 3 : Trie ==>> dictionary
/// 4 : Network Routing algorithm

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using namespace std;

template <class T> struct TreeNode {
  T val;
  TreeNode<int> *left;
  TreeNode<int> *right;
  TreeNode<int>(T val) : val(val), left(nullptr), right(nullptr){};
  TreeNode<int>(T val, TreeNode<int> *left, TreeNode<int> *right)
      : val(val), left(left), right(right){};
};

#endif
