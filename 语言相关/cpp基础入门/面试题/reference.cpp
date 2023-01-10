/**
引用到底占不占用内存
错误大难
*/

#include <iostream>
using namespace std;

int main() {
  int a = 10;
  //int &b = a;
	//
	//text	   data	    bss	    dec	    hex	filename
  //1712	    656	      8	   2376	    948	a.out
  // cout << "b's size is : " << sizeof(int &) << endl;
  // cout << "b's size is : " << sizeof(char &) << endl;
  // cout << "b's size is : " << sizeof(float &) << endl;
  // cout << "b's size is : " << sizeof(double &) << endl;
  // b's size is : 4
  // b's size is : 1
  // b's size is : 4
  // b's size is : 8
  //  引用的内存空间大小就是所引用对象的大小？？？
  //  https://mp.weixin.qq.com/s/zJ02yMbQmhEFlcVJiZKMoA
  //  一本正经的错误，哈哈哈哈哈哈

  // C++编译器在编译时会把指针做为引用的实际实现
  // 引用所占用的内存与指针所占用的内存一样
  // 上述sizeof实际查看的是所引用对象的内存大小

  // cout << "b's size is : " << sizeof(int *) << endl;
  // cout << "b's size is : " << sizeof(char *) << endl;
  // cout << "b's size is : " << sizeof(float *) << endl;
  // cout << "b's size is : " << sizeof(double *) << endl;
  //b's size is : 8
  //b's size is : 8
  //b's size is : 8
  //b's size is : 8

  // 可以用unix下的size命令行来精准查看引用的大小

  return 0;
}
