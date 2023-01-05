/**
 * 1 : 构造函数的坑
 * 2 : 深浅拷贝的区别
 */
#include <iostream>
using namespace std;
class A {
private:
  int len;

public:
  A(int len) : len(len) {}
  void print(){
    cout << &len << " : " <<  len << endl;
  }
};

int main(){
  A a(5);
  A b = a;
  a.print();
  b.print();
  return 0;
}