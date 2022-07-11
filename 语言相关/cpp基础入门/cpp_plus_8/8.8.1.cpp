/**
 * @file 8.8.1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
using namespace std;
void printString(std::string *);
void printString(std::string *, unsigned int);
int times = 0;
int main(void)
{
    std::string str = "efefefef";
    std::string *test = &str;
    printString(test);
    printString(test, 3);
    return 0;
};
void printString(std::string *str)
{
    times++;
    std::cout << *str << endl;
};
void printString(std::string *str, unsigned int a)
{
    times++;
    for (unsigned int i = 0; i < times; i++)
    {
        std::cout << *str << endl;
    }
};