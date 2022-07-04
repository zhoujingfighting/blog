/**
 * @file 6.11.2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cctype>
int main(void)
{
    using namespace std;
    const int len = 10;
    double donation[len];
    double input;
    double sum = 0.0;
    int numbers = 0;
    cout << "please enter your value: ";
    for (int i = 0; i < len && cin >> input; i++)
    { //最多循环十次
        numbers++;
        cin.get();
        donation[i] = input;
        sum += input;        
        cout << "please enter your value: ";
    } //拿到donation数组
    double average = sum / numbers;
    int count = 0;
    for (int i = 0; i < numbers; i++)
    {
        if (donation[i] > average)
        {
            count++;
        }
    }
    cout << "Average value is: " << average << endl;
    cout << "there are " << count << " elements greater than" << endl;
    return 0;
}