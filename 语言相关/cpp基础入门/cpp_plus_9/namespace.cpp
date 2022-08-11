#include <iostream>
#include "namespace.h"
using namespace std;
/**
 * 需要对原型进行声明
 */
namespace pers { //没有分号
    using std::cin;
    using std::cout;
    void getPerson(Person &person){
        cout << "Enter first name: ";
        cin >> person.fname;
        cout << "Enter last name: ";
        cin >> person.lname;
    }

    void showPerson(const Person& person){
        cout << person.fname << " , " << person.lname << std::endl;
    }
}

namespace debts {//再debts这个名称空间里面使用其他结构体
    void getDebt(Debt &dt) {
        getPerson(dt.name);//获取欠债人的信息
        std::cout << "Enter debt: ";
        std::cin >> dt.mount;
    }
}

int main(void){
    pers::Person per;
    pers::getPerson(per);//::双冒号限定作用域
    pers::showPerson(per);
    return 0;
}