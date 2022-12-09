#include <iostream>
#include<stdlib.h>
extern void swap(int *input, int start, int end);
void quickSort(int* input,int start,int end){
	if(start >= end)
		return;
    int flag = rand() % end +start;
    int flagNumber = input[flag];
    swap(input, end, flag);
    int i = start - 1;
    for(int j = start ; j <= end ; j++) {
        if(input[j] <= flagNumber ) {
            i++;
            swap(input, i,j);
        }
    }
    i++;
    swap(input, i, end);
    quickSort(input,start,i-1);
    quickSort(input,i+1,end);
}

int main() {
  int Input[10] = {1, -2, 5, 9, 6, 10, 29, 4, 100, 78}; // The tested array
  int size = sizeof(Input) / sizeof(int);
  quickSort(Input, 0, size-1);
  for(int i = 0 ; i < size ; i ++) {
    std::cout << Input[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}