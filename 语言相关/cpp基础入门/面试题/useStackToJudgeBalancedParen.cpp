/**
 * @file useStackToJudgeBalancedParen.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stack>
#include <string>

/// @brief Judge a paren string is valid or not
/// @param Paren A paren string
/// @return A boolean value
bool isValidParen(std::string Paren) {
  std::stack<char> ParenStack;
  for (int i = 0; i < Paren.size(); i++) {
    switch (Paren[i]) {
    case ')':
      if (ParenStack.top() == '(' && !ParenStack.empty() ) {
        ParenStack.pop();
        continue;
      }
      ParenStack.push(Paren[i]);
      break;
    case '}':
      if (ParenStack.top() == '{' && !ParenStack.empty()) {
        ParenStack.pop();
        continue;
      }
      ParenStack.push(Paren[i]);
      break;
    case ']':
      if (ParenStack.top() == '[' && !ParenStack.empty()) {
        ParenStack.pop();
        continue;
      }
      ParenStack.push(Paren[i]);
      break;
    default:
      ParenStack.push(Paren[i]);
    }
  }
  return ParenStack.empty();
}

int main() {
  std::string Ref = "((())){(})";
  if (isValidParen(Ref))
    std::cout << "Valid" << std::endl;
  else
    std::cout << "Not Valid" << std::endl;
  return 0;
}
