/**
 * @file 6.11.7.cpp
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
using namespace std;
int main(void)
{

    char *input;
    while (cin >> input)
    {
        if (input == "q")
        {
            std::cout << "End" << endl;
        }
    }
    return 0;
}