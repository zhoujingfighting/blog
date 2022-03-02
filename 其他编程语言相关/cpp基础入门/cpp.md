## 第二章

### 2.5 命名空间
用于具体区分使用的哪个函数:
例如A公司有一个函数print
B公司也有一个函数print
可以使用A::print()来特指使用A公司的方法


```cpp
#include <iostream>
int main(){
    using namespace std;
    cout<<
    //或者
    using std::cout;//make sout available
    using std::cin;//make cin avalable
}
```

  * 2.5.x 函数定义
  
```cpp
void symon(int n);//提前声明!!function prototype!!
int main(){
    return 0;
}
void symon(int n){
    return 3;
}
```
### 2.6 复习题

    * q1:C++程序的模块叫什么
      * 函数
    * q2:下列的预处理器是做什么用的
        ```cpp
        #include<iostream>
        ```
      * 包含iostream头文件,将头文件内容包含到源代码中

    * q3:下面语句有什么用
        ```cpp
        using namespace std;
        ```
        * 预编译指令,使用std命名空间
    * q11:编译器指出cout是一个未知参数,三个解决办法?
    ```cpp
    using namespace std;
    using std::cout;
    std::cout;
    ```
### 2.7 练习题

> q1: 编写一个C++程序，它显示您的姓名和地址。
 
 ```cpp


 ```