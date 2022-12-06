/**
 * define a swap function to swap to elemnts in an array
*/
#include <iostream>
void swap(int *input, int start, int end) {
    if(start != end) {
        int tmp = input[start];
        input[start] = input[end];
        input[end] = tmp;
    }
}

void printStep(int *input, int size) {
    for(int i = 0 ; i < size ; i ++) {
        std::cout << input[i] << " ";
    }
}