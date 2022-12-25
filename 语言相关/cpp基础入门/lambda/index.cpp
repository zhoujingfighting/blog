#include "iostream"
using namespace std;

int main() {
  auto func = [](int){
    std::cout << "hello" << std::endl;
	};
  func(1);
	// 
	[](int){
    std::cout << "hello1" << std::endl;
	}(1);
  return 0;
  }