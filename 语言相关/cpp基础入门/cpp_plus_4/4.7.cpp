/**
 * @file 4.7.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Pizza
{
    char *company_name;
    float pizza_radius;
    float weight;
};

char *getLine();
int main(void)
{
    Pizza pizza;
    std::cout << "请输入您的公司名称" << std::endl;
    pizza.company_name = getLine(); //拿到公司的名称
    std::cout << "请输入披萨直径" << std::endl;
    cin >> pizza.pizza_radius;
    std::cout << "请输入披萨重量" << std::endl;
    cin >> pizza.weight;
    std::cout << "您的公司名称是: " << pizza.company_name << endl;
    std::cout << "您的披萨直径是: " << pizza.pizza_radius << endl;
    std::cout << "您的披萨重量是: " << pizza.weight << endl;
    delete pizza.company_name;//需要注重内存的问题
    return 0;
}

char *getLine()
{
    char temp[80];
    std::cin.getline(temp, 80);
    char *result = new char(strlen(temp) + 1);
    strcpy(result, temp);
    return result;
}