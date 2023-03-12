#include <iostream>
using namespace std;

template  <bool debug>
int sum(int n) {
  int res = 0;
  for (int i = 0; i < n; i++){
    res +=  i;
    if(debug)
      cout << res << endl;
  }
  return res;
}

int main() {

  cout << sum<true>(8) << endl;
  cout << sum<false>(8) << endl;
  return 0;
}