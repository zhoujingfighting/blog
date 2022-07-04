
/**
 * @file 5.9_课后练习(1).cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 1.编写一个要求用户输入两个整数的程序。该程序将计算并输出 这两个整数之间(包括这两个整数)所有整数的和。这里假设先输入较 小的整数。
 * 例如，如果用户输入的是2和9，则程序将指出2~9之间所有 整数的和为44。
 */
#include <iostream>
using namespace std;

int main(void){

	int a,b;
	std::cout << "请输入您的起始值: " << std::endl;
	cin >> a; 
	std::cout << "请输入您的结束值: " << std::endl;
	cin >> b;
	int sum = 0;
	int start;
	for(start = int(a);start <= int(b);++start){
		sum += start;	
	};
	std::cout << "总和是：" << sum << std::endl;
	return 0;
}
