//\\ all lines in this file will be on BEGIN of the prepostfunctions.c
//\\ lines starts with //\\ will be ignored
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include <stdint.h>	// required by uintptr_t in C99

typedef unsigned long long gomp_ull;
typedef _Bool bool;
typedef long TYPE;

#define BUFFER_SIZE 10240

// just print the values that was called
void print(char *name, int qtd)
{
	if(qtd) {
		printf("%s: %d\n", name, qtd);
	}
}

