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
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val),left(left),right(right){};
};
