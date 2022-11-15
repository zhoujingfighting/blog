/**
 * this is a helper function
 */

#include "list-node.h"
#include <iostream>
using namespace std;

ListNode *convertArrayToListNode(vector<int> Array) {
    ListNode *Dummy = new ListNode(0);
    ListNode *Head = Dummy;
    for(auto Node : Array) {
        Head->next = new ListNode(Node);
        Head = Head->next;
    }
    return Dummy->next;
}