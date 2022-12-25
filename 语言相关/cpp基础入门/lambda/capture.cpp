#include "iostream"
using namespace std;

int main() {
  int c = 12;
  // capture list is a copy of value
  auto func = [c]() { std::cout << c << std::endl; };
  for(size_t i = 0 ; i < 5 ; i ++) {
    func();
    ++c;
  }

    int d = 12;
  // Use reference to access new value
  auto func1 = [&d]() { std::cout << d << std::endl; };
  for(size_t i = 0 ; i < 5 ; i ++) {
    func1();
    ++d;
  }
  return 0;
}