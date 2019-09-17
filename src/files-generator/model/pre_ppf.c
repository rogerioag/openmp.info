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
#define RESULT_NAME "result.json"

// file to save the results
FILE *fp = NULL;

void open_json()
{
	fp = fopen(RESULT_NAME, "w");
	fprintf(fp, "{\n");
	fprintf(fp, "\"%s\": {\n", __FILE__);
}

void close_json()
{
	// return 2 bytes in file to delete the last ',\n'
	fseek(fp, ftell(fp)-2, 0);
	fprintf(fp, "\n    }\n");
	fprintf(fp, "}");
	fclose(fp);
}

void print_json(char *name, int qtd)
{
	fprintf(fp, "    \"%s\": %d,\n", name, qtd);
}

// just print the values that was called
void print(char *name, int qtd)
{
	if(qtd) {
		printf("%s: %d\n", name, qtd);
	}

	print_json(name, qtd);
}

