#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>  
#include<numeric> // reduce算法
using namespace std;
int sum = 0;
void add(int vi) {
    sum+=vi;
}
int main() {
  vector<int> Test{1,2,3,4,5}; 

  // for_each 模板算法
  for_each(Test.begin(), Test.end(), add);  
  cout << sum << endl;
  // reduce
  auto test = std::reduce(Test.begin(), Test.end(), std::plus<>();// -std=c++17
  cout << test << endl;
  return 0; 
}