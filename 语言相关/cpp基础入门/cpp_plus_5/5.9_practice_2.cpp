/**
 * @file 5.9_课后练习(2).cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 * 1.编写一个要求用户输入两个整数的程序。
 * 该程序将计算并输出 这两个整数之间(包括这两个整数)所有整数的和。这里假设先输入较 小的整数。例如，如果用户输入的是2和9，则程序将指出2~9之间所有 整数的和为44。
 */
#include <iostream>
#include <array>
using namespace std;
const int size = 100;
int main(void)
{

    array<long double, size> sum_array;
    long double result = 1;
    int start;
    for (start = 1; start <= size; start++)
    {
        result *= start;
        sum_array[start - 1] = result;
    };
    std::cout << size << "的阶乘结果是: " << result << std::endl;
    return 0;
}