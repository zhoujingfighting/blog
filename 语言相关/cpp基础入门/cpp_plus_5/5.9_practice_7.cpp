/**
 * @file 5.9_practice_3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 * 设计一个名为car的结构，用它存储下述有关汽车的信息:生产商(存储在字符数组或string对象中的字符串)、生产年份(整数)
 * 编写一个程序，向用户询问有多少辆汽车。随后，程序使用new来创建 一个由相应数量的car结构组成的动态数组。
 * 接下来，程序提示用户输 入每辆车的生产商(可能由多个单词组成)和年份信息。请注意，这需 要特别小心，因为它将交替读取数值和字符串(参见第4章)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct car
{
    std::string productor;
    int production_year;
};

int main(void)
{
    int car_number;
    std::cout << "How many cars do you want to catalog?" << endl;
    (std::cin >> car_number).get();
    vector<car> information(car_number);
    int i;
    for (i = 1; i <= car_number; i++)
    {
        std::cout << "Car #" << i << " : " << endl;
        std::cout << "Please enter the make: ";
        std::getline(std::cin, information[i - 1].productor);
        (std::cin >> information[i - 1].production_year).get();
    };
    for (auto x : information)
    {
        std::cout << x.productor << " " << x.production_year << std::endl;
    }
    return 0;
}