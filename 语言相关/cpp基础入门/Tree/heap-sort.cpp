/**
 * 堆排序练习
 */

#include "tree-node.h"
#include <cmath>
#include <vector>
using namespace std;

// 第一步:建造大顶堆

// 1.1 构建完全二叉树, 层次遍历
TreeNode *makeHeap(vector<int> &InputArr) {
  if (!InputArr.size())
    return nullptr;
  vector<TreeNode *> Tmp;
  for (int i = 0; i < InputArr.size(); i++)
    Tmp[i] = new TreeNode(InputArr[i]);
  for (size_t i = 0; i < ceil(InputArr.size() / 2); i++) {
    if (Tmp[2 * i])
      Tmp[i]->left = Tmp[2 * i];
    if (Tmp[2 * i + 1])
      Tmp[i]->right = Tmp[2 * i + 1];
  }
  return Tmp[0];
}

int main() {
  vector<int> test = {1,2,34,5,6,7};
  TreeNode *Result = makeHeap(test);
  cout << 1 << endl;
  cout << &Result << endl;
  return 0;
}