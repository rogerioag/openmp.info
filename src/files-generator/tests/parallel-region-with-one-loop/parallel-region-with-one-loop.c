#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs() (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

int main() {
  int i;
  
  #pragma omp parallel num_threads(2)
  {
    #pragma omp for schedule(dynamic)
    for (i = 0; i < 10; i++) {
      printf("omp thread: %lu, thread: %lu, iteration: %d\n", omp_get_thread_num(), pthread_self(), i);
    }
  }
  
  printf("Fora da região paralela.\n");
    
  return 0;
}
