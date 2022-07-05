/**
 * @file 6.6.5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
unsigned long fabricator(int);

int main( void ) {
    
    int input;
    while( cin >> input){
        cin.get();//清除缓存
        std::cout << fabricator(input) <<endl;
    }
    return 0;
}

unsigned long fabricator(int number){
    if(number == 1) 
        return 1;
    return number * fabricator(number - 1);
}
