#include <iostream>
#include <string>
//右值不能绑定在非常量的引用中去
// 可以参考一下wzh之前的ppt
using namespace std;

//void func(string &str);
void func(const string &str);

int main(void)
{
        func("ABC");  //"ABC"  --> string对象   隐式转换，  临时string对象
        // "ABC"隐式转换成string对象，调用了string的构造函数
        // 为什么临时对象是右值？
        // 左值的话至少有个变量名吧？？
        return 0;
}

void func(const string &str)
{
}