/**
 * @file infixToPostfix.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief using stack to convert infix expression to postFix expression
 * @version 0.1
 * @date 2022-11-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <limits.h>

using namespace std;

std::map<char, int> OperatorPre{{'+', 10}, {'-', 10}, {'*', 20}, {'/', 20}, {'(', INT_MIN}};

/// @brief Judge whether a paren is an opening flag
/// @param input an input char token
/// @return a boolean flag
bool isOpenParen(char input) {
  switch (input) {
  case '(':
  case '{':
  case '[':
    return true;
  default:
    return false;
  }
}
/// @brief Judge whether a paren is an closing flag
/// @param input an input char token
/// @return a boolean flag
bool isClosParen(char input) {
  switch (input) {
  case ')':
  case '}':
  case ']':
    return true;
  default:
    return false;
  }
}

bool isOperator(char ope) {
  switch (ope) {
  case '+':
  case '-':
  case '*':
  case '/':
    return true;
  default:
    return false;
  }
}

/// Input is a infix string, for example it can be  like this:((A+B)*C-D)*E
/// The postfix expression AB+C*D-E*
std::string infixToPostfix(std::string Input) {
  stack<char> Operands;
  string Result = "";
  for (int i = 0; i < Input.size(); i++) {
    if (isOpenParen(Input[i])) {
      Operands.push(Input[i]);
    } else if (isClosParen(Input[i])) {
      while (!isOpenParen(Operands.top())) {
        Result += Operands.top();
        Operands.pop();
      }
      Operands.pop(); //
    } else if (isOperator(Input[i])) {
      // If top of stack operator's priority is higher than Input[i]
      // pop top and append Input[i] to Result
      if (!Operands.empty() && OperatorPre[Operands.top()] > OperatorPre[Input[i]]) {
        Result += Operands.top();
        Operands.pop();
      }
      Operands.push(Input[i]);
    } else {
      // Pure char to be appended into Result
      Result += Input[i];
    }
  }
  // If the stack is not empty, add all these operators to Result
  while (!Operands.empty()) {
    Result += Operands.top();
    Operands.pop();
  }
  return Result;
}

int main( ) {
  string Test = "((A+B)*C-D)*E";
  std::cout << "===<<>>====" << endl;
  std::cout << infixToPostfix(Test) << endl;
  return 0;
}