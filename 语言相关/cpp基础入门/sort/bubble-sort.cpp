
#include <iostream>

extern void swap(int *input, int start, int end);
extern void printStep(int *input, int size);
void bubbleSort(int *input, int size) {
  int start = 1;
  std::cout << "***********BubbleSort***********" << std::endl;
  for (int i = size - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (input[j + 1] < input[j])
        swap(input, j, j + 1);
    }
    std::printf("The input array after %d times bubble sort: ", size - i);
    printStep(input, size);
    std::cout << std::endl;
  }
}

int main() {
  int Input[10] = {1, -2, 5, 9, 6, 10, 29, 4, 100, 78}; // The tested array
  int size = sizeof(Input) / sizeof(int);
  bubbleSort(Input, size);
  return 0;
}