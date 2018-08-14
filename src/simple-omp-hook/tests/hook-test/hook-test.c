#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{ 

  #pragma omp parallel
  {
    int i;
    #pragma omp for schedule (static)
    for (i = 0; i < 10; i++)
      printf("Static for\n");

    #pragma omp for schedule (dynamic)
    for (i = 0; i < 10; i++)
      printf("Dynamic for\n");

    #pragma omp barrier
    printf("Barrier\n");

    #pragma omp single
    printf("Single\n");

    #pragma omp critical
    printf("Critical\n");

    #pragma omp sections
    {
        #pragma omp section
        printf("Section\n");
    }
     

    #pragma omp task
    printf("Task\n");
  }

  return 0;
}
