## 第三章练习题

### 1为什么C++有多种整形
int short long long long unsigned signed char
根据数据运算的需要选择合适的数据类型和应用进行匹配

### 2声明一下数据类型

2．声明与下述描述相符的变量。
a．short整数，值为80
b．unsigned int整数，值为42110
c．值为3000000000的整数


* short a = 80
* unsigned int b = 80;
* unsigned int c  = 3000000000; long c = 3000000000;

### 3．C++提供了什么措施来防止超出整型的范围？

编译器不会主动提供这个功能帮助编译器实现,需要程序员自己实现
每种数据类型的宽度,c++并没有做规定,具体的值由开发平台与编译器决定

### 4 33l与33的区别

默认c++整数在不超出`int`范围的应用情况下,默认优先使用`int`类型

33 : int 类型
33L: 以long类型来存储整数常量

### 5 下面两条C++语句是否等价?

char grade = 65;
char grade = 'A';

在基于ASCII码的平台下,两者是等价的,但是`char grade = 65`先将`65`存储为int类型,然后再将`int`类型转换成`char`类型

### 6 如何使用C++来找出编码88表示的字符？指出至少两种方法。
```c++
char ch = 88;
std::cout << ch << endl;
std::cout << (char)88 << endl;
```

### 7．将long值赋给float变量会导致舍入误差，将long值赋给double变量呢？将long long值赋给double变量呢？

不同平台和编译器对应的long和long long类型的大小是不同的,如果long长度是4字节,则存放在double类型中不会出现舍入误差
如果long long是8字节,则会出现误差


```c++
#include <iostream>

using namespace std;

int main(void)
{
    std::cout << sizeof(int) << endl;
    std::cout << sizeof(float) << endl;
    std::cout << sizeof(double) << endl;
    std::cout << sizeof(long) << endl;
    std::cout << sizeof(long long) << endl;
}
```

