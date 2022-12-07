/**
 * 这道题主要是想强调getchar的坑,可以 man getchar看一下getchar的返回值类型
 */

#include <stdio.h>
#include <limits.h>
int main(void) {
  int c;
  // char c;
  printf("char: %d ---- %d\n", SCHAR_MIN, SCHAR_MAX);
  while ((c = getchar()) != EOF)
    putchar(c);
  return 0;
}

// if we use char c here
// maybe on some compiler, char is defined to be default unsigned char(0-255)
// but the marco EOF = -1, so the dead loop will form