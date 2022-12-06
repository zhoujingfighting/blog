
#include <iostream>
#include <vector>

extern void swap(int *input, int start, int end);
extern void printStep(int *input, int size);
void insertSort(int *input, int size) {
    int start = 1;
    std::cout << "***********InsetSort***********" << std::endl;
    while(start < size ) {
        for(int i = start; i > 0; i--) {
            if(input[i] < input[i - 1])
                swap(input, i, i-1);
        }
        std::printf("After %d times sort, array is: ",start);
        printStep(input,size);
        std::cout << std::endl;        
        start++;
    }

}

int main() {
  int Input[10] = {1, -2, 5, 9, 6, 10, 29, 4, 100, 78}; // The tested array
  int size = sizeof(Input) / sizeof(int);
  insertSort(Input, size);
  return 0;
}