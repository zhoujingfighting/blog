#include <vector>
#include <iostream>
using namespace std;

/*
 * 1 ： 动态分配空间的连续数组
 * 2 ： 效率很高
 * 3 : fast insert/remove at the end: O(1)
 * 4 : slow insert/remove at the beginning or in the middle: O(n)
 * 5 : slow search : O(n)??
 */
int main(void){

    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(7);
    cout << vec1[2];
    //cout << vec1.at(4); //out of range

    for(int i = 0 ; i < vec1.size();i++){
       cout << vec1[i] << endl; 
    };// 普通的遍历

    for(vector<int>::iterator itr = vec1.begin() ; itr != vec1.end();++itr) {
        cout << *itr << endl;
    };

    return 0;
}