/**
 * @file 6.11.6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
using namespace std;
struct DonationInformation
{
    string name;
    double money;
};

int main(void){
    int person;
    std::cout << "Please enter person numbers: ";
    (cin >> person).get(); //获取人数
    DonationInformation donator[person];
    for(int i = 0 ; i < person ; i ++) { 
            std::cout << "Please enter name: ";
            std::getline(std::cin, donator[i].name);
            std::cout << "Please enter stored money: ";
            (std::cin >> donator[i].money).get();
    }
    std::cout << "The below are \'Grand Patrons\'" << endl;
    for(auto donate : donator){
        if(donate.money > 10000){
            std::cout << donate.name << std::endl;
        }
    }
    std::cout << "The below are \'Other Patrons\'" << endl;
    for (auto donate : donator) {
        if(donate.money <= 10000){
            if(!donate.name.empty()){
                std::cout << donate.name << endl;
            } else {
                std::cout << "none" << endl;
            }
        }
    }
    return 0;
}
