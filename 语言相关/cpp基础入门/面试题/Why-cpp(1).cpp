
#include<iostream>
using namespace std;
void func_1(int *&);
void func_2(int *&);
int a = 10;
int main(void) {
	int *p = NULL;
	func_1(p);
}

void func_1(int *&p) { func_2(p); }

void func_2(int *&p) {
  p = &a;
  if (p)
	cout << p << endl;
}
/**
 * 下面是上述C++代码的C语言实现
 * 可以看到如果方程再往下嵌套的话，C语言的代码的可读性会变的非常差
 * 
 * #include <stdio.h>
 * void func_1(int **);
 * void func_2(int ***);
 * int a = 10;
 * int main(void) {
 * 	int *p = NULL;
 * 	func_1(&p);
 * }
 * 
 * void func_1(int **p) { func_2(&p); }
 * 
 * void func_2(int ***p) {
 *  **p = &a;
 * if (p)
 * 	printf("%p\n", p);
 * }
 * 
 * 
 * 
 * 
 * 
*/