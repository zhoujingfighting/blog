/**
 * @file 6.11.3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
using namespace std;
struct bop
{
    std::string fullname;
    std::string title;
    std::string bopname;
    int preference;
};
int main(void)
{
    bop bops[4] = {
        {"zhoujing",
         "professor",
         "JayChou",
         1},
        {"zhoujing1",
         "professor1",
         "JayChou1",
         1},
        {"zhoujing2",
         "professor2",
         "JayChou2",
         1},
        {"zhoujing3",
         "professor3",
         "JayChou3",
         1}};
    std::cout << "Benevolent Order of Programmer report" << std::endl;
    std::cout << "a. display by name" << '\t' << "b. display by title" << std::endl;
    std::cout << "c. display by bopname" << '\t' << "d. display by preference" << std::endl;
    std::cout << "q. quit" << std::endl;
    char input;
    std::cout << "Enter your choice: ";
    while (cin >> input)
    {

        if (input == 'a')
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << bops[i].fullname << endl;
            }
        }
        else if (input == 'b')
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << bops[i].title << endl;
            }
        }
        else if (input == 'c')
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << bops[i].bopname << endl;
            }
        }
        else if (input == 'd') //根据输入选择来进行判断
        {
            for (int i = 0; i < 4; i++)
            {
                switch (bops[i].preference)
                {
                case 0:
                    std::cout << bops[i].fullname << endl;
                    break;
                case 1:
                    std::cout << bops[i].title << endl;
                    break;
                case 3:
                    std::cout << bops[i].bopname << endl;
                    break;
                default:
                    break;
                }
                std::cout << bops[i].bopname << endl;
            }
        }
        else if (input == 'q')
        {
            cout << "Bye!" << endl; // ending
            break;
        }
        std::cout << "Next choice: ";
    }
    return 0;
}
