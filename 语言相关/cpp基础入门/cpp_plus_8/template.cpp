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
template <typename T>

void swap(T &x, T &y){ //
    T temp = x;
    x = y;
    y = temp;
}

int main(void){
    using namespace std;
    int a = 10;
    int b = 17;
    ::swap(a,b); //不加冒号会提示出swap is ambiguous的错误
    std::cout << a << endl;
    std::cout << b << endl;
    return 0;
}
