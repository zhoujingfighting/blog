/**
 * Select sort: https://en.wikipedia.org/wiki/Selection_sort
*/

#include <iostream>
#include <vector>

extern void swap(int *input, int start, int end);
extern void printStep(int *input, int size);
void selectSort(int *input, int size) {
    int start = 0;
    std::cout << "***********SelectSort***********" << std::endl;
    // find the minest elemnt in the array
    while(start < size) {
        int min = input[start];
        int flag = start;
        for(int i = start; i < size; i++){
            if(input[i] < min) {
                min = input[i];
                flag = i;
            }
        }
        swap(input,start,flag);
        std::printf("After %d times sort, array is: ",start);
        printStep(input,size);
        std::cout << std::endl;  
        start++;
    }
}

int main() {
  int Input[10] = {1, -2, 5, 9, 6, 10, 29, 4, 100, 78}; // The tested array
  int size = sizeof(Input) / sizeof(int);
  selectSort(Input, size);
  return 0;
}