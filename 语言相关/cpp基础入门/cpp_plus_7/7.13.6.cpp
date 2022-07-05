/**
 * @file 7.13.6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
void Fill_array(vector<double> *, int );
void Show_array(vector<double>*, int);
int main(void) { 
    vector<double> demo;
    vector<double> *opera = &demo;
    Fill_array(opera, 6);
    Show_array(opera, 6);
    return 0;
}

void Fill_array(vector<double> *arr, int size){
    std::cout << "Please enter numbers: " << endl;
    double input;
    while(arr->size() < size ){
        (cin >> input).get();        
        arr->push_back(input);
    }
}

void Show_array(vector<double> *arr, int size){
    std::cout << "The array elements are as belows: " << endl;
    for( auto ele : *arr){
        std::cout << ele << endl;
    }
}

