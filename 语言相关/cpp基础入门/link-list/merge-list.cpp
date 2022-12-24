

#include "list-node.h"
#include <vector>
using namespace std;
extern ListNode *convertArrayToListNode(vector<int> Array);

int findMinNode(vector<ListNode *> &lists) {
  ListNode *root = nullptr;
  ListNode *record = nullptr;
  int MIN = 10001;
  int flag = 0;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i]) {
      if (lists[i]->val <= MIN) {
        MIN = lists[i]->val;
        record = lists[i];
        flag = i;
      }
    }
  }
  if (record) {
    lists[flag] = record->next;
  }
  return MIN;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
  ListNode *root = new ListNode();
  if (!lists.size())
    return nullptr;
  while (findMinNode(lists) != 10001) {
    root->next = new ListNode(findMinNode(lists));
    root = root->next;
  }
  return root->next;
}

int main() {
  vector<vector<int>> Input;
  Input[0] = {1, 4, 5};
  Input[1] = {1, 3, 4};
  Input[2] = {2, 6};
  vector<ListNode *> test;
  for (int i = 0; i < Input.size(); i++) {
    test[i] = convertArrayToListNode(Input[i]);
  }
  ListNode *result = mergeKLists(test);
  while (result) {
    cout << result->val << endl;
    result = result->next;
  }
  return 0;
}