/**
 * @file 6.11.1.cpp
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
    char input;
    cin.get(input);
    while (input != '@')
    {
        if (isdigit(input))
        {
            cin.get(input);
            continue;
        }
        else if (isupper(input))
        {
            input = tolower(input);
        }
        else if (islower(input))
        {
            input = toupper(input);
        }
        cout << input;
        cin.get(input);
    }
    cout << endl;
    return 0;
}