#include <iostream>
#include <memory>
int main() {
  //以下方法创建出空的智能
  std::unique_ptr<int> a();
  std::unique_ptr<int> b(nullptr);

  //创建一个非空指针
  std::unique_ptr<int> c(new int(3));

  //实验指针的方法
  int *test = c.release(); //释放c的内存，所以这之后c为空指针

  if (!c) {
    std::cout << "C的内存已经被释放!!" << std::endl;
  }

  std::unique_ptr<int> e(new int(4));
  std::unique_ptr<int> d = std::move(e);

  std::cout << test << std::endl;
  std::cout << &d << std::endl;
  if (!e) {
    std::cout << "e的内存已经被释放!!" << std::endl;
  }
  return 0;
}