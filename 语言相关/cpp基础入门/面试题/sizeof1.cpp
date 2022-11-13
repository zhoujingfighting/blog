/*
假设在64位的操作系统下，一个int类型占用4个字节，则：

1）int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pt = arr;
	那么：
	sizeof(arr)是多少？
	sizeof(pt)是多少？

2）void func(int array[], int n)
	{
		printf("size of array = %ld\n", sizeof(array));
	}
*/

// 1 : sizeof 是运算符
// 2 : 数组名不能自增, 指针可以
// 3 : 指针指向的是一个地址, 64位地址就是8*8, 8字节

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int *pt = arr;
    //Sizeof是个运算符, 这里取决于电脑是多少位的系统
    cout << "arr's size is: " << sizeof(arr) << endl;
    cout << "pt's size is: " << sizeof(pt) << endl;
    return 0;
}

/**
 * arr's size is: 40
 * pt's size is: 8
 */