#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    std::cout << "请输入您的基准身高：" << endl;
    int height;
    std::cin >> height;
    std::cout << "您的基准身高是：" << height << "英尺" << std::endl;
    std::cout << "请输入您的身高：" << endl;
    int _height;
    std::cin >> _height;
    std::cout << "您的身高是：" << _height << "英寸" << std::endl;
    std::cout << "请输入您的体重：" << endl;
    double weight;
    std::cin >> weight;
    std::cout << "您的基本体重是：" << weight << "磅" << std::endl;
    double ibm = weight / 2.2 / pow((height * 12 + _height) * 0.0254, 2);
    std::cout << "您的IBM指数是: " << ibm << std::endl;
    return 0;
}
