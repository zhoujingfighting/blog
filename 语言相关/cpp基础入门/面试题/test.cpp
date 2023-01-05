#include <iostream>
using namespace std;

int main() {
  int *p = new int(12);
  int *b = p;
  cout << *b << endl;
  delete p;
  // here free the memory,b pointer has nowhere to point to
  cout << *b << endl;
  return 0;
}