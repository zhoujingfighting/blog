/**
 * @file template.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;
template <typename T>
void swap(T &x, T &y) { //
    T temp = x;
    x = y;
    y = temp;
}
template <class T, class U = char>
class Test{
public:        
    Test():index1(12), index2(123.00){
        //构造函数
       std::cout << "Being created!!" << endl;
    };
    T index1;
    U index2;
};
int main(void){
    using namespace std;
    int a = 10;
    int b = 17;
    ::swap(a,b); //不加冒号会提示出swap is ambiguous的错误
    std::cout << a << endl;
    std::cout << b << endl;

    //test class template
    Test<int, double> Index;
    std::cout << Index.index1 << endl;
    std::cout << Index.index2 << endl;
    return 0;
}
