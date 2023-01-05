#include <iostream>
using namespace std;

int main() {
  int *p = new int;
  *p = 12;
  int *b = p;
  int *c = p;
  *c = 2;
  cout << *b << endl;
  delete p;
  c = nullptr;
  // here free the memory,b pointer has nowhere to point to
  cout << *p << " : " << p << endl;
  cout << *b << " : " << b << endl;
  cout << *c << " : " << c << endl;
  // FIXME: 
  return 0;
}