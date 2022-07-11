/**
 * @file 8.8.2.cpp
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
struct CandyBar
{
    const char* brand;
    double weight;
    int heat;
};
void formatCandyBar( CandyBar &, char *, double, int);
int main(void){
    CandyBar candy;
    formatCandyBar(candy, "zhoujing", 23.3, 1234);
    return 0;
};

void formatCandyBar( CandyBar &candy, char *str, double wgt, int heat) {
    candy.brand = str;
    candy.weight = wgt;
    candy.heat = heat;
    printf("%s %f %d", candy.brand, candy.weight, candy.heat);
}

