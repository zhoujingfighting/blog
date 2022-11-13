/**
 * @file stack.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-11-13
 *
 * Implement a stack ADT by vector
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

template <class T> class Stack {
  int Top = -1;
  // Here we use dynamic array to store the element
  vector<T> Elements;

public:
  void pop();           // Pop the top element from stack
  void push(T Element); // Push the element to the top of stack
  T top();              // Get the top element from the stack
  bool isEmpty();    // A boolean flag to see whether the stack is empty or not
  void printStack(); // Print all the elements in the stack
};

template <class T> void Stack<T>::pop() {
  if (isEmpty()) {
    cout << "Stack is empty, can not pop" << endl;
    return;
  }
  Elements.pop_back();
  Top--;
}

template <class T> void Stack<T>::push(T Element) {
  Elements.push_back(Element);
  Top++;
}

template <class T> T Stack<T>::top() {
  // FIXME: here need to be modified
  return Elements[Top];
}

template <class T> bool Stack<T>::isEmpty() { return Elements.empty(); }

template <class T> void Stack<T>::printStack() {
  if (isEmpty()) {
    cout << "*****Stack is empty*****" << endl;
    return;
  }
  cout << "Stack elements are : ";
  for (auto element : Elements) {
    // FIXME: Other data structure should be overloaded
    cout << element << " ";
  }
  cout << endl;
}

// Test the stack function

int main() {
  Stack<int> Test;
  Test.push(12);
  Test.printStack();
  Test.push(24);
  Test.printStack();
  Test.pop();
  Test.printStack();
  Test.pop();
  Test.printStack();
  Test.push(36);
  Test.printStack();
  cout << Test.top() << endl;
  return 0;
}