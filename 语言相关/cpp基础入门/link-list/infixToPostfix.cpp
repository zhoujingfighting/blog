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

using namespace std;

std::map<char, int> OperatorPre{{'+', 10}, {'-', 10}, {'*', 20}, {'/', 20}};

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

/// Input is a infix string, for example it can be  like this:((A+B)*C-D)*E
/// The postfix expression AB+*CD-E*
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
    }
  }
}

int main() { return 0; }