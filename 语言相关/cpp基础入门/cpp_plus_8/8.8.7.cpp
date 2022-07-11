/**
 * @file 8.8.7.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
typedef struct debts
{
    char name[50];
    double amount;
} debt;
template <typename T> T SumArray( T*, int n);
template <typename T> T SumArray(T *arr[], int);
int main(void)
{
    using namespace std;
    int thins[6] = {13, 31, 103, 301, 310, 130};
    double *dt[3];
    debt mr_E[3]
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    for(int i = 0 ; i < 3 ; i++){
        (*dt)[i] = mr_E[i].amount;
    }
    cout << "efefe" << endl;
    cout << "Things数组的和是: " << SumArray(thins, 6) << endl;
    cout << " mr_E数组的和是: " << SumArray(dt, 3) << endl;
    return 0;
}

//简单计算整型数组和
template <typename T>
T SumArray(T *input, int n){
    T result = 0;
    for(int i = 0 ; i < n ; i ++){
        result += input[i];
    }
    return result;
}

//计算debt数组里面每一项值的集合
template <typename T>
T SumArray(T **input, int n){
    T result = 0;
    for(int i = 0 ; i < n; i ++){
        result += (*input)[i];
    }
    return result;
}