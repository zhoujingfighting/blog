#include <iostream>
using namespace std;
int main() {
  unsigned char a = 16;
  char b = '8';
  auto c = a * b; // 隐式提升到整型
  unsigned d = 2 << 15;
  int e = (2 << 15);
  auto f = d * e - 1; // sign promotion, 到无符号整数
  cout << f << "\n";
  cout << (int)d << "\n";
  return 0;
}