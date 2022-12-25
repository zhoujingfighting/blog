#include "iostream"
using namespace std;

int main() {
  auto func = [](int){
    std::cout << "hello" << std::endl;
	};
  func(1);
	// 立即方程
	[](int){
    std::cout << "hello1" << std::endl;
	}(1);
	// Lambda function with returned value
	auto func2 = [](double a, double b){
    return a+b;
	};
	cout << func2(1.2, 3.45) << endl;

	// Lambda function with returned value explicitly
	auto func3 = [](double a, double b) -> double {
    return a+b;
	};
	cout << func2(1.23, 3.45) << endl;
  return 0;
  }