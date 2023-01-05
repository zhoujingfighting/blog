/**
 * 1 : 构造函数的坑
 * 2 : 深浅拷贝的区别
 */
#include <iostream>
using namespace std;
class A {
private:
  int len;
  int *pt;

public:
  A(int len, int *p) : len(len) {
    pt = new int(*p);
    // Here we can not use syntax below, we need to
    // pt = p
    // destructor will free the memory , what we thought is free the memory
    // owned by the class itself the syntax above will free the memory the
    // pointer points to which is owned by other object
  }
  A(const A &a) {
    len = a.len;
    pt = new int(*a.pt);
  }
  ~A() { delete pt; }
  void print() {
    cout << "len's address: " << &len << " : " << len << endl;
    cout << "pt's address: " << pt << " : " << *pt << endl;
  }
};

int main() {
  int i = 100;
  cout << "i's address: " << &i << " : " << i << endl;
  A a(5, &i);
  A b(a); // A b(a) = A b = a;
  a.print();
  b.print();
  /*
  i's address: 0x7ffcf4afacf8 : 100
  len's address: 0x7ffcf4aface8 : 5
  pt's address: 0x560939ab42c0 : 100
  len's address: 0x7ffcf4afacd8 : 5
  pt's address: 0x560939ab42c0 : 100
  */

  // That is to say : shallow copy
  // b's pt pointer point to the same memory space which belongs to a's pointer
  // but a'pt pointer's space is created by itself, after a is destructed,
  // when b is destructed, b's pt pointer points to nowhere, the destructor will
  // cause problems(pointer hanging)
  return 0;
}