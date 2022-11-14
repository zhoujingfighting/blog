/**
 * this is a helper function
 */

#include "list-node.h"
#include <vector>
#include <iostream>
using namespace std;

ListNode *convertArrayToListNode() {
    // FIXME: need to be changed
    vector<int> Array = {1,2,3,4,5,6,7,8};
    ListNode *Dummy = new ListNode(0);
    ListNode *Head = Dummy;
    for(auto Node : Array) {
        Head->next = new ListNode(Node);
        Head = Head->next;
    }
    // This is to test convert function works or not
    ListNode *Test = Dummy;
    while(Test->next) {
        cout << Test->next->val << endl;
        Test = Test->next;
    }
}

// to test
int main(){
    convertArrayToListNode();
    return 0;
}