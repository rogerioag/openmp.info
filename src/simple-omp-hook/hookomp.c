/* 
	TODO:  (jorge)
		- conferir se está faltando/sobrando funções
		- corrigir nomes nos TRACEs

*/

#include "hookomp.h"

typedef unsigned long long gomp_ull;
typedef long TYPE;

/* ------------------------------------------------------------- */
/* Test function.                                                */
void foo(void)
{
	puts("Hello, I'm a shared library.\n");
}

/* ------------------------------------------------------------- */
/* barrier.c
/* ------------------------------------------------------------- */
void GOMP_barrier(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier, "GOMP_barrier");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_barrier.\n", (unsigned long int)pthread_self());
	PRE_GOMP_barrier();
	lib_GOMP_barrier();
	POST_GOMP_barrier();
}

/* ------------------------------------------------------------- */
bool GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier_cancel, "GOMP_barrier_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_barrier_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_barrier_cancel();
	bool result = lib_GOMP_barrier_cancel();
	POST_GOMP_barrier_cancel();
	return result;
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* critical.c
/* ------------------------------------------------------------- */
void GOMP_critical_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_start, "GOMP_critical_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_start();
	lib_GOMP_critical_start();
	POST_GOMP_critical_start();
}

/* ------------------------------------------------------------- */
void GOMP_critical_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_end, "GOMP_critical_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_end();
	lib_GOMP_critical_end();
	POST_GOMP_critical_end();
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_start, "GOMP_critical_name_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_name_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_name_start(pptr);
	lib_GOMP_critical_name_start(pptr);
	POST_GOMP_critical_name_start(pptr);
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_end, "GOMP_critical_name_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_name_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_name_end(pptr);
	lib_GOMP_critical_name_end(pptr);
	POST_GOMP_critical_name_end(pptr);
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* loop.c
/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_start, "GOMP_loop_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	bool result = lib_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	POST_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_start, "GOMP_loop_ordered_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	bool result = lib_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	POST_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_runtime_start, "GOMP_loop_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
	bool result = lib_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
	POST_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_next, "GOMP_loop_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_runtime_next(istart, iend);
	bool result = lib_GOMP_loop_runtime_next(istart, iend);
	POST_GOMP_loop_runtime_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_next, "GOMP_loop_ordered_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_runtime_next(istart, iend);
	bool result = lib_GOMP_loop_ordered_runtime_next(istart, iend);
	POST_GOMP_loop_ordered_runtime_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static_start, "GOMP_parallel_loop_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_static_start(fn, data, num_threads, start, end, incr, chunk_size);
	lib_GOMP_parallel_loop_static_start(fn, data, num_threads, start, end, incr, chunk_size);
	POST_GOMP_parallel_loop_static_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic_start, "GOMP_parallel_loop_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
	lib_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
	POST_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided_start, "GOMP_parallel_loop_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
	lib_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
	POST_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime_start, "GOMP_parallel_loop_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
	lib_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
	POST_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static, "GOMP_parallel_loop_static");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_static.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic, "GOMP_parallel_loop_dynamic");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_dynamic.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided, "GOMP_parallel_loop_guided");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_guided.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_dynamic, "GOMP_parallel_loop_nonmonotonic_dynamic");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_dynamic.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_guided, "GOMP_parallel_loop_nonmonotonic_guided");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_guided.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime, "GOMP_parallel_loop_runtime");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_runtime.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
	lib_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
	POST_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
}

/* ------------------------------------------------------------- */
void GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end, "GOMP_loop_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end();
	lib_GOMP_loop_end();
	POST_GOMP_loop_end();
}

/* ------------------------------------------------------------- */
bool GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_cancel, "GOMP_loop_end_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end_cancel();
	bool result = lib_GOMP_loop_end_cancel();
	POST_GOMP_loop_end_cancel();
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_nowait, "GOMP_loop_end_nowait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end_nowait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end_nowait();
	lib_GOMP_loop_end_nowait();
	POST_GOMP_loop_end_nowait();
}

/* ------------------------------------------------------------- */
bool GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_start, "GOMP_loop_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_start, "GOMP_loop_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_start, "GOMP_loop_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_start, "GOMP_loop_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_start, "GOMP_loop_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_start, "GOMP_loop_ordered_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_start, "GOMP_loop_ordered_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_start, "GOMP_loop_ordered_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_static_start, "GOMP_loop_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_dynamic_start, "GOMP_loop_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_guided_start, "GOMP_loop_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_next, "GOMP_loop_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_static_next(istart, iend);
	bool result = lib_GOMP_loop_static_next(istart, iend);
	POST_GOMP_loop_static_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_next, "GOMP_loop_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_dynamic_next(istart, iend);
	POST_GOMP_loop_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_next, "GOMP_loop_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_guided_next(istart, iend);
	bool result = lib_GOMP_loop_guided_next(istart, iend);
	POST_GOMP_loop_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_next, "GOMP_loop_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
	POST_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_next, "GOMP_loop_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_next(istart, iend);
	bool result = lib_GOMP_loop_nonmonotonic_guided_next(istart, iend);
	POST_GOMP_loop_nonmonotonic_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_next, "GOMP_loop_ordered_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_static_next(istart, iend);
	bool result = lib_GOMP_loop_ordered_static_next(istart, iend);
	POST_GOMP_loop_ordered_static_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_next, "GOMP_loop_ordered_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_ordered_dynamic_next(istart, iend);
	POST_GOMP_loop_ordered_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_next, "GOMP_loop_ordered_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_guided_next(istart, iend);
	bool result = lib_GOMP_loop_ordered_guided_next(istart, iend);
	POST_GOMP_loop_ordered_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* loop_ull.c
/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_start, "GOMP_loop_ull_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	bool result = lib_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	POST_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_start, "GOMP_loop_ull_ordered_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	POST_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_runtime_start, "GOMP_loop_ull_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
	bool result = lib_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
	POST_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_next, "GOMP_loop_ull_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_runtime_next(istart, iend);
	bool result = lib_GOMP_loop_ull_runtime_next(istart, iend);
	POST_GOMP_loop_ull_runtime_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_next, "GOMP_loop_ull_ordered_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	POST_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_start, "GOMP_loop_ull_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_start, "GOMP_loop_ull_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_start, "GOMP_loop_ull_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_start, "GOMP_loop_ull_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_start, "GOMP_loop_ull_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_start, "GOMP_loop_ull_ordered_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_start, "GOMP_loop_ull_ordered_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_start, "GOMP_loop_ull_ordered_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_static_start, "GOMP_loop_ull_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_dynamic_start, "GOMP_loop_ull_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_guided_start, "GOMP_loop_ull_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	bool result = lib_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_next, "GOMP_loop_ull_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_static_next(istart, iend);
	bool result = lib_GOMP_loop_ull_static_next(istart, iend);
	POST_GOMP_loop_ull_static_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_next, "GOMP_loop_ull_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_ull_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_next, "GOMP_loop_ull_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_guided_next(istart, iend);
	bool result = lib_GOMP_loop_ull_guided_next(istart, iend);
	POST_GOMP_loop_ull_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_next, "GOMP_loop_ull_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_next, "GOMP_loop_ull_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
	bool result = lib_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_next, "GOMP_loop_ull_ordered_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_static_next(istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_static_next(istart, iend);
	POST_GOMP_loop_ull_ordered_static_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_next, "GOMP_loop_ull_ordered_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_next, "GOMP_loop_ull_ordered_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_guided_next(istart, iend);
	bool result = lib_GOMP_loop_ull_ordered_guided_next(istart, iend);
	POST_GOMP_loop_ull_ordered_guided_next(istart, iend);
	return result;
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* ordered.c
/* ------------------------------------------------------------- */
void GOMP_ordered_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_start, "GOMP_ordered_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_ordered_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_ordered_start();
	lib_GOMP_ordered_start();
	POST_GOMP_ordered_start();
}

/* ------------------------------------------------------------- */
void GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_end, "GOMP_ordered_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_ordered_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_ordered_end();
	lib_GOMP_ordered_end();
	POST_GOMP_ordered_end();
}

/* ------------------------------------------------------------- */
void GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_post, "GOMP_doacross_post");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_post.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_post(counts);
	lib_GOMP_doacross_post(counts);
	POST_GOMP_doacross_post(counts);
}

/* ------------------------------------------------------------- */
void GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_wait, "GOMP_doacross_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_wait(first);
	lib_GOMP_doacross_wait(first);
	POST_GOMP_doacross_wait(first);
}

/* ------------------------------------------------------------- */
void GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_post, "GOMP_doacross_ull_post");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_post.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_post(counts);
	lib_GOMP_doacross_ull_post(counts);
	POST_GOMP_doacross_ull_post(counts);
}

/* ------------------------------------------------------------- */
void GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_wait, "GOMP_doacross_ull_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_wait(first);
	lib_GOMP_doacross_ull_wait(first);
	POST_GOMP_doacross_ull_wait(first);
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* parallel.c
/* ------------------------------------------------------------- */
void GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_start, "GOMP_parallel_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_start(fn, data, num_threads);
	lib_GOMP_parallel_start(fn, data, num_threads);
	POST_GOMP_parallel_start(fn, data, num_threads);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_end, "GOMP_parallel_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_end();
	lib_GOMP_parallel_end();
	POST_GOMP_parallel_end();
}

/* ------------------------------------------------------------- */
void GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel, "GOMP_parallel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel(fn, data, num_threads, flags);
	lib_GOMP_parallel(fn, data, num_threads, flags);
	POST_GOMP_parallel(fn, data, num_threads, flags);
}

/* ------------------------------------------------------------- */
bool GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_cancellation_point, "GOMP_cancellation_point");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_cancellation_point.\n", (unsigned long int)pthread_self());
	PRE_GOMP_cancellation_point(which);
	bool result = lib_GOMP_cancellation_point(which);
	POST_GOMP_cancellation_point(which);
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_cancel, "GOMP_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_cancel(which, do_cancel);
	bool result = lib_GOMP_cancel(which, do_cancel);
	POST_GOMP_cancel(which, do_cancel);
	return result;
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* sections.c
/* ------------------------------------------------------------- */
unsigned GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_start, "GOMP_sections_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_start(count);
	unsigned result = lib_GOMP_sections_start(count);
	POST_GOMP_sections_start(count);
	return result;
}

/* ------------------------------------------------------------- */
unsigned GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_next, "GOMP_sections_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_next();
	unsigned result = lib_GOMP_sections_next();
	POST_GOMP_sections_next();
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections_start, "GOMP_parallel_sections_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_sections_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_sections_start(fn, data, num_threads, count);
	lib_GOMP_parallel_sections_start(fn, data, num_threads, count);
	POST_GOMP_parallel_sections_start(fn, data, num_threads, count);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections, "GOMP_parallel_sections");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_sections.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_sections(fn, data, num_threads, count, flags);
	lib_GOMP_parallel_sections(fn, data, num_threads, count, flags);
	POST_GOMP_parallel_sections(fn, data, num_threads, count, flags);
}

/* ------------------------------------------------------------- */
void GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end, "GOMP_sections_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end();
	lib_GOMP_sections_end();
	POST_GOMP_sections_end();
}

/* ------------------------------------------------------------- */
bool GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_cancel, "GOMP_sections_end_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end_cancel();
	bool result = lib_GOMP_sections_end_cancel();
	POST_GOMP_sections_end_cancel();
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_nowait, "GOMP_sections_end_nowait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end_nowait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end_nowait();
	lib_GOMP_sections_end_nowait();
	POST_GOMP_sections_end_nowait();
}

/* ------------------------------------------------------------- */

/* ------------------------------------------------------------- */
/* single.c
/* ------------------------------------------------------------- */
bool GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_single_start, "GOMP_single_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_single_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_single_start();
	bool result = lib_GOMP_single_start();
	POST_GOMP_single_start();
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_start, "GOMP_single_copy_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_single_copy_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_single_copy_start();
	lib_GOMP_single_copy_start();
	POST_GOMP_single_copy_start();
}

/* ------------------------------------------------------------- */
void GOMP_single_copy_end(void *data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_end, "GOMP_single_copy_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_single_copy_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_single_copy_end(data);
	lib_GOMP_single_copy_end(data);
	POST_GOMP_single_copy_end(data);
}

/* ------------------------------------------------------------- */
