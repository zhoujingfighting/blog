#include <cstdlib>
#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREAD 5

void *printHello(void *threadid) {
  long tid;
  tid = (long)threadid;
  cout << "Hello World! Thread ID, " << tid << endl;
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREAD];
  int rc;
  int i;
  for (i = 0; i < NUM_THREAD; i++) {
    cout << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, printHello, (void *)i);

    if (rc) {
      cout << "Error:unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  return 0;
}
