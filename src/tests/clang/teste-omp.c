//test.c
#include "omp.h"
#include <stdio.h>
#include <pthread.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs()                             \
  (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

int main(void) {
  
  fprintf(stdout, "Thread[%lu,%lu]: Antes da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel num_threads(4)
  {
      fprintf(stdout, "  Thread[%lu,%lu]: Na região paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());
  }

  fprintf(stdout, "Thread[%lu,%lu]: Depois da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

}

