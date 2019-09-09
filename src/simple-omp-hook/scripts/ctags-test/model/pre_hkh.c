//\\ all lines in this file will be at BEGIN of the hookomp.h
//\\ lines starts with //\\ will be ignored
#ifndef hookomp_h__
#define hookomp_h__

#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include "debug.h"

#include "prepostdef.h"

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#endif

typedef unsigned long long gomp_ull;
typedef long TYPE;

#define PRINT_ERROR()                    \
    do                                   \
    {                                    \
        char *error;                     \
        if ((error = dlerror()) != NULL) \
        {                                \
            fputs(error, stderr);        \
        }                                \
    } while (0)

#define GET_RUNTIME_FUNCTION(hook_func_pointer, func_name)                                    \
    do                                                                                        \
    {                                                                                         \
        if (hook_func_pointer)                                                                \
            break;                                                                            \
        void *__handle = RTLD_NEXT;                                                           \
        hook_func_pointer = (typeof(hook_func_pointer))(uintptr_t)dlsym(__handle, func_name); \
        PRINT_ERROR();                                                                        \
    } while (0)

/* Tipo para o ponteiro de função. */
typedef void (*op_func)(void);

/* Ponteiros para as funções que serão recuperadas pela macro get runtime function.*/
