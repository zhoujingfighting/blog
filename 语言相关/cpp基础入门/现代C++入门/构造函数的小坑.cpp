#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
struct Pig {
  int Weight;
  explicit Pig(int weight) : Weight(weight) {}
};
void show(Pig pig) { cout << pig.Weight << endl; }

int main() { 
    Pig pig{80};
    show(Pig{90});// 这种情况等同于 Pig pig = 80;
    return 0; }