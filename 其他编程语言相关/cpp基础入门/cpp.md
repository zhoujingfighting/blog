## 第一个cpp程序

* 2.1.5 命名空间
用于具体区分使用的哪个函数:
例如A公司有一个函数print
B公司也有一个函数print
可以使用A::print()来特指使用A公司的方法
* 2.1.6 cout输出流


```cpp

int main(){
    using namespace std;
    cout<<
    //或者
    using std::cout;//make sout available
    using std::cin;//make cin avalable
}

```