#include "first_test.h"

int fac(int n) {
    if(n == 0 || n ==1)
        return n;
    else if(n <0)
        return -1;
    return fac(n-1) * n;
}