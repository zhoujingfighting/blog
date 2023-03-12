#include "tree-node.h"
#include <cmath>
#include <cstddef>
#include <math.h>
#include <vector>
using namespace std;

// 第一步:建造大顶堆

// 1.1 构建完全二叉树, 层次遍历
vector<TreeNode<int> *> makeHeap(vector<int> InputArr) {
  vector<TreeNode<int> *> Tmp;
  if (!InputArr.size())
    return Tmp;
  for (int i = 0; i < InputArr.size(); i++) {
    Tmp.push_back(new TreeNode<int>(InputArr[i]));
    cout << Tmp[i] << endl;
  }
  for (size_t i = 0; i < ceil(InputArr.size() / 2); i++) {
    if (Tmp[2 * i + 1])
      Tmp[i]->left = Tmp[2 * i + 1];
    if (Tmp[2 * i + 2])
      Tmp[i]->right = Tmp[2 * i + 2];
  }
  return Tmp;
}

// 1.2 遍历整个树,来完成堆排序
void buildHeap(vector<int> Input) {
  static vector<TreeNode<int> *> heap = makeHeap(Input);
  static int start = ceil(log2(Input.size())) - 1;
  for (int i = start; i >= 0; i--) {
    if (heap[2 * i + 2] != nullptr) {
      if (heap[2 * i + 2]->val > heap[i]->val) {
        int tmp = heap[2 * i + 2]->val;
        heap[2 * i + 2]->val = heap[i]->val;
        heap[i]->val = tmp;
        buildHeap(Input);
      }
    }
    if (heap[2 * i + 1] != nullptr) {
      if (heap[2 * i + 1]->val > heap[i]->val) {
        int tmp = heap[2 * i + 1]->val;
        heap[2 * i + 1]->val = heap[i]->val;
        heap[i]->val = tmp;
        buildHeap(Input);
      }
    }
  }
  cout << heap[0] << endl;
}

int main() {
  vector<int> test = {1, 2, 34, 5, 6, 7};
  cout << &test << endl;
  buildHeap(test);
  return 0;
}