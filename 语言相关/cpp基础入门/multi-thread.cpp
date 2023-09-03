#include <iostream>
#include <thread>
#include <pthread.h>

void function1(char symbol) {
  for (int i = 0; i < 200; i++) {
    std::cout << symbol;
  }
  std::cout << std::endl;
}

void function2() {
  for (int i = 0; i < 200; i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
}

int main() {
  std::thread work1(function1, 'o');
  std::thread work2(function2);
  system("parse>nul");
}