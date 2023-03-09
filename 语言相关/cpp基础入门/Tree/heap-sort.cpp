/**
 * 堆排序练习
 */

#include "tree-node.h"
#include <cmath>
#include <vector>
using namespace std;

// 第一步:建造大顶堆

// 1.1 构建完全二叉树, 层次遍历
TreeNode<int> * makeHeap(vector<int> InputArr) {
  if (!InputArr.size())
    return nullptr;
  vector<TreeNode<int> *> Tmp;
  for (int i = 0; i < InputArr.size(); i++) {
    Tmp.push_back(new TreeNode<int>(InputArr[i]));
    cout << Tmp[i] << endl;
  }
  for (size_t i = 0; i < ceil(InputArr.size() / 2); i++) {
    if (Tmp[2 * i + 1])
      Tmp[i]->left = Tmp[2 * i+1];
    if (Tmp[2 * i + 2])
      Tmp[i]->right = Tmp[2 * i + 2];
  }
  return Tmp[0];
}

// int main() {
//   vector<int> test = {1, 2, 34, 5, 6, 7};
//   cout << &test << endl;
//   TreeNode<int> *Test = makeHeap(test);
//   cout << Test << endl;
//   return 0;
// }