
/// 编写一段代码,查看一个文件的大小

#include <iostream>
#include <fstream>
#include <stdio.h>
int main() {
    FILE *fp;
    long int size = 0;
    fp = fopen("D:\\front-end-learning\\boke\\package.json","r");
    fseek(fp,0,SEEK_END); //定位到文件末尾
    size = ftell(fp);//直到文件末尾的位置
    fclose(fp);
    std::cout << "Size is : " << size << std::endl;
    return 0;
}