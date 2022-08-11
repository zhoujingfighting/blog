//函数原型以及结构体的定义
//#include <>
#include <string>

namespace pers {

    struct Person {
        std::string fname;
        std::string lname;
    };
    
    void showPerson(const Person &);
    
    void getPerson(Person &);

}

namespace debts {
    using namespace pers;

    struct Debt {
        Person name;
        double mount;
    };
    
    void getDebt(Debt &);
}
