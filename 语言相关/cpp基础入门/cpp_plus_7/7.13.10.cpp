/**
 * @file 7.13.10.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector> 
using namespace std;
const int size  = 3;
double add(double x, double y) { return x + y; };
double mut(double x, double y) { return x * y; };
double sub(double x, double y) { return x - y; };
void calculator(double, double, double (*pf[])(double, double), int);

int main(void)
{   
    double x, y;
    double (*pf[size])(double, double) = {add, mut, sub};//初始化一个
    while(cin >> x ){
        cin.get();
        (cin >>y).get();
        calculator(x, y, pf, size);

    }
    return 0;
}

void calculator(double x, double y, double (*pf[])(double, double), int n){
    for( int i = 0 ; i < n ; i ++){
        std::cout << pf[i](x, y) << endl;
    }
};
