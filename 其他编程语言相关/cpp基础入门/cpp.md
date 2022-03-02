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
#include <iostream>

using namespace std;

int main(){
    std::cout << "我的名字叫周晶!" << endl;
    std:cout << "我住在武汉！" << endl;
    return 0;
}
 ```
> q2: 编写一个C++程序，它要求用户输入一个以long为单位的距离，然后将它转换为码（一long等于220码）

```cpp
#include <iostream>

using namespace std;

int count(int number);
int main(){
    std::cout << "请输入数字：";
    int a;
    std::cin >> a;
    std::cout << "转换之后的码数是：" << count(a) << endl;
    return count(a);
}
int count(int number){
    return 220 * number; 
}
```
> q7: 编写一个C++程序，要求用户输入小孩数与分钟数。在main()中，将这两个值传递给一个void函数，后面以下面这样的格式显示这样的值

```cpp
#include <iostream>

using namespace std;

int count(int number);
int main(){
    std::cout << "Enter the number of hours: ";
    int hour;
    std::cin >> hour;
    std::cout << "Enter the number of minutes: ";
    int minute;
    std::cin >> minute;
    std::cout << "Time: " << hour << ":" << minute << endl;
    return 0;
}
```
