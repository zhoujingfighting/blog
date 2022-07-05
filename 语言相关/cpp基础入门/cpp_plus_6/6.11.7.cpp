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
#include <string>
int main(void)
{
    using namespace std;
    char input;
    cout << "Enter words (q to quit): " << endl;
    int owl = 0; //元音
    int fal = 0; //辅音
    string value = "";
    while (cin.get(input))
    {
        if (input == 'q')
        {
            break;
            cout << "Break" << endl;
        }
        if (input == '\n')
        {
            cin.get();
            continue;
        }
        else if (input == ' ')
        {
            if(isalpha(value[0])){//首字母是字符
                switch (tolower(value[0]))
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    owl++;
                    break;
                
                default:
                    fal++;
                }
            }
            value = "";
        }
        else
        {
            value.push_back(input);
        }
        cout << input << endl;
    }
    cout << owl <<" words begining with vowels" << endl;
    cout << fal <<" words begining with consonants" << endl;
    return 0;
}