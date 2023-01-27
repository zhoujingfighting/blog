/*
int (*func(int i))[10]
是什么意思？
*/

#include <iostream>
using namespace std;
//int (*pt[10])(int)
//int (*func(int i))[10] ---> int
int arr[10];
int (*func(int i))[10]; // ---> 不管怎样func是个函数，有返回值，
int (*func(int i))[10] {
  for(int j = 0 ; j < 10 ; j++) {
    arr[j] = j+1;
  }
  return &arr;
}

int main() {
  auto p = func(2);
  int *pt = (int *)p;
  for(int j = 0 ; j < 10 ; j++) {
    cout << pt[j] << " ";
  }
  cout << endl;
  //Output is: 1 2 3 4 5 6 7 8 9 10
  return 0;
} 


/*
知识点回顾:
int *p[10];
1: 指向数组的指针指向的是一整个数组占用的内存地址，是一个内存快
2: int *pt = (int *)p  --->强制类型转换把数组指针转换成整数指针，指向数组的第一个地址
*/