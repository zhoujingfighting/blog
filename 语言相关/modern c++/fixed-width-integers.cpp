#include <cstdint>
#include <iostream>
using namespace std;
int main() {
  int8_t var;
  cin >> var;  // read '2'
  cout << var; // print '2'
  int a = var * 2;
  cout << a; // print '100' !! 这里的
  return 0;
}