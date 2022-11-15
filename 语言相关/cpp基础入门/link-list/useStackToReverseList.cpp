/**
 * @file useStackToReverseList.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-14
 * 
 * Use stack to reverse Link List
 * @copyright Copyright (c) 2022
 * 
 */
#include "list-node.h"
#include <stack>

extern ListNode *convertArrayToListNode(std::vector<int> Array);

/// @brief Can use recursive to reverse, but that way is ineffective,so We use this function
/// @param InputList The to be reversed ListNode
/// @return a new ListNode
ListNode *reverseListByStack(std::vector<int> Input){
    //std::vector<int> Input = {1,2,3,4,5,6,7,8,9};  // The tested array
    std::stack<int> Stack;
    ListNode *InputList = convertArrayToListNode(Input);
    while(InputList) {
        Stack.push(InputList->val);
        InputList = InputList->next;
    }
    // Now, we need to pop Stack to get new ListNode
    ListNode *Dummy = new ListNode(0);
    ListNode *Head = Dummy;
    while(!Stack.empty()) {
        Dummy->next = new ListNode(Stack.top());
        Stack.pop();
        Dummy = Dummy->next;
    }
    return Head->next;
}

int main() {
    std::vector<int> Input = {1,2,3,4,5,6,7,8,9};  // The tested array
    ListNode *ReversedList = reverseListByStack(Input);
    while(ReversedList) {
        std::cout << ReversedList->val << std::endl;
        ReversedList = ReversedList->next;
    }
    return 0;
}
