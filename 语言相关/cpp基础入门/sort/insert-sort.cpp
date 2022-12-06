
#include <iostream>
#include <vector>

extern void swap(int *input, int start, int end);
extern void print(int *input, int size);
void insertSort(int *input, int size) {
    int start = 1;
    while(start <= size ) {
        for(int i = start; i > 0; i--) {
            if(input[i] < input[i - 1])
                swap(input, i, i-1);
        }
        start++;
    }
}

int main() {
  int Input[10] = {1, -2, 5, 9, 6, 10, 29, 4, 100, 78}; // The tested array
  int size = sizeof(Input) / sizeof(int);
  insertSort(Input, size);
  print(Input,size);
  return 0;
}