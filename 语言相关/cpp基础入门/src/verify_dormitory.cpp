// 验证一个输入的字符串是不是一个符合某个学生宿舍的分布
// HUST:zhoujing@zisong.10.315.4

#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

enum State { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, UNREACHEABLE };

using namespace std;

State getNextState(int PreviousState, char Tmp) {
  switch (PreviousState) {
  case State::ZERO: {
    if (isalpha(Tmp))
      return State::ONE;
    return State::UNREACHEABLE;
  }

  case State::ONE: {
    if (isalpha(Tmp))
      return State::ONE;
    else if (Tmp == '@')
      return State::TWO;
    return State::UNREACHEABLE;
  }
  case State::TWO: {
    if (isalpha(Tmp))
      return State::TWO;
    else if (Tmp == '.')
      return State::THREE;
    return State::UNREACHEABLE;
  }
  case State::THREE: {
    if (isdigit(Tmp))
      return State::THREE;
    else if (Tmp == '.')
      return State::FOUR;
    return State::UNREACHEABLE;
  }
  case State::FOUR: {
    if (isdigit(Tmp))
      return State::FOUR;
    else if (Tmp == '.')
      return State::FIVE;
    return State::UNREACHEABLE;
  }
  case State::FIVE: {
    if (isdigit(Tmp))
      return State::SIX;
    return State::UNREACHEABLE;
  }
  case State::SIX: {
    return State::UNREACHEABLE;
  }
  default:
    return State::UNREACHEABLE;
  }
}

bool isValidDormitoryRoom(const char *Input) {
  int InitialState = State::ZERO;
  while (*Input != '\0') {
    InitialState = getNextState(InitialState, *Input);
    Input++;
  }

  // last step: check state
  if (InitialState != State::SIX)
    return false;

  return true;
}
