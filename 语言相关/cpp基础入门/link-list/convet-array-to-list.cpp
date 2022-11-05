/**
 * this is a helper function
 */

#include "list-node.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> toVector() {
    // TODO: fix this
    int input[3] = {1,2,3};
    vector<int> Input;
    for(int i = 0 ; i < 3 ; i ++){
        Input.push_back(input[i]);
    }
    return Input;
}

ListNode *convertArrayToListNode() {
    vector<int> Input(toVector());
    ListNode *Dummy = new ListNode(0);
    ListNode *Head = Dummy;
    for(auto Node : Input) {
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