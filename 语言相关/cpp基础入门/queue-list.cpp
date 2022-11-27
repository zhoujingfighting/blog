/**
 * @file queue-vector.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-11-27
 *
 * @copyright Copyright (c) 2022
 *
 */

/// Queue ADT
/// Can only be performed on only one end(insert at the end)
/// FIFO(First in first out)

/// Operations
/// Enqueue, Deque, front, IsEmpty

#include "link-list/list-node.h"
#include <iostream>
#include <vector>

using namespace std;

/// FIXME: manually new a link list

/// We use link-list to implement a Queue
class Queue {
private:
  ListNode *Top = nullptr; // Top element
  ListNode *Rear = nullptr; // Tail element

public:
  Queue(vector<int>);
  ~Queue() { delete Top; };

  void enQueue(int);
  void deQueue();
  int front();
  bool isEmpty();
  void printQue();
};

/// @brief Initialize a link-list by the construct function
/// @param InitializedNumbers
Queue::Queue(vector<int> InitializedNumbers) {
  // if empty, return directly
  if (InitializedNumbers.empty())
    return;
  ListNode *Dummy = Top;
  for (auto init : InitializedNumbers) {
    ListNode *NewNode = new ListNode(init);
    Dummy->next = NewNode;
    Dummy = Dummy->next;
  }
  Rear = Dummy; // The tail element
  // Now we finish initializing the queue
}

void Queue::deQueue() {
  if (!Top) {
    cout << "Queue is empty, can not dequeue, please check";
    return;
  }
  if (Top == Rear) {
    Top = Rear = nullptr;
    return;
  }
  ListNode *Dummy = Top;
  Top = Top->next;
  Dummy->next = nullptr;
  delete Dummy;
}

void Queue::enQueue(int element) { Rear->next = new ListNode(element); }

bool Queue::isEmpty() { return Top == nullptr; }

int Queue::front() {
  if (Top)
    return Top->val;
  cout << "Queue is empty, can not get top element" << endl;
  return NULL;
}

void Queue::printQue() {
  ListNode *Dummy = Top;
  cout << "Queue: ";
  while (Dummy) {
    cout << Dummy->val << " ";
    Dummy = Dummy->next;
  }
  cout << endl;
}

int main() {
  Queue Que({1, 2, 3, 4, 5, 6});
  Que.enQueue(7);
  Que.printQue(); // Enter an element to queue
  Que.deQueue();
  Que.printQue(); // Pop an element from queue

  Que.deQueue();
  Que.deQueue();
  Que.deQueue();
  Que.deQueue();
  Que.deQueue();
  Que.deQueue();
  // Que Should be empty here
  if (Que.isEmpty()) {
    cout << "***Que is empty***" << endl;
  }
  return 0;
}