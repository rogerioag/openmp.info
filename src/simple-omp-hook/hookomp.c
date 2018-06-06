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
/* atomic.c
/* ------------------------------------------------------------- */
void GOMP_atomic_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_end, "GOMP_atomic_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_atomic_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_atomic_end();
	lib_GOMP_atomic_end();
	POST_GOMP_atomic_end();
}

void GOMP_atomic_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_start, "GOMP_atomic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_atomic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_atomic_start();
	lib_GOMP_atomic_start();
	POST_GOMP_atomic_start();
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

bool GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier_cancel, "GOMP_barrier_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_barrier_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_barrier_cancel();
	lib_GOMP_barrier_cancel();
	POST_GOMP_barrier_cancel();
}

/* ------------------------------------------------------------- */
/* critical.c
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

void GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_end, "GOMP_critical_name_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_name_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_name_end(pptr);
	lib_GOMP_critical_name_end(pptr);
	POST_GOMP_critical_name_end(pptr);
}

void GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_start, "GOMP_critical_name_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_critical_name_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_critical_name_start(pptr);
	lib_GOMP_critical_name_start(pptr);
	POST_GOMP_critical_name_start(pptr);
}

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
/* loop.c
/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_dynamic_start, "GOMP_loop_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_guided_start, "GOMP_loop_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_runtime_start, "GOMP_loop_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
	lib_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
	POST_GOMP_loop_doacross_runtime_start(ncounts, counts, istart, iend);
}

bool GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_static_start, "GOMP_loop_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_next, "GOMP_loop_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_dynamic_next(istart, iend);
	lib_GOMP_loop_dynamic_next(istart, iend);
	POST_GOMP_loop_dynamic_next(istart, iend);
}

bool GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_start, "GOMP_loop_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);
}

void GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end, "GOMP_loop_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end();
	lib_GOMP_loop_end();
	POST_GOMP_loop_end();
}

bool GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_cancel, "GOMP_loop_end_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end_cancel();
	lib_GOMP_loop_end_cancel();
	POST_GOMP_loop_end_cancel();
}

void GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_nowait, "GOMP_loop_end_nowait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_end_nowait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_end_nowait();
	lib_GOMP_loop_end_nowait();
	POST_GOMP_loop_end_nowait();
}

bool GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_next, "GOMP_loop_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_guided_next(istart, iend);
	lib_GOMP_loop_guided_next(istart, iend);
	POST_GOMP_loop_guided_next(istart, iend);
}

bool GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_start, "GOMP_loop_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_next, "GOMP_loop_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
	lib_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
	POST_GOMP_loop_nonmonotonic_dynamic_next(istart, iend);
}

bool GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_start, "GOMP_loop_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_nonmonotonic_dynamic_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_next, "GOMP_loop_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_next(istart, iend);
	lib_GOMP_loop_nonmonotonic_guided_next(istart, iend);
	POST_GOMP_loop_nonmonotonic_guided_next(istart, iend);
}

bool GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_start, "GOMP_loop_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_nonmonotonic_guided_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_next, "GOMP_loop_ordered_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_dynamic_next(istart, iend);
	lib_GOMP_loop_ordered_dynamic_next(istart, iend);
	POST_GOMP_loop_ordered_dynamic_next(istart, iend);
}

bool GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_start, "GOMP_loop_ordered_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_next, "GOMP_loop_ordered_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_guided_next(istart, iend);
	lib_GOMP_loop_ordered_guided_next(istart, iend);
	POST_GOMP_loop_ordered_guided_next(istart, iend);
}

bool GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_start, "GOMP_loop_ordered_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_next, "GOMP_loop_ordered_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_runtime_next(istart, iend);
	lib_GOMP_loop_ordered_runtime_next(istart, iend);
	POST_GOMP_loop_ordered_runtime_next(istart, iend);
}

bool GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_start, "GOMP_loop_ordered_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	lib_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	POST_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
}

bool GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_next, "GOMP_loop_ordered_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_static_next(istart, iend);
	lib_GOMP_loop_ordered_static_next(istart, iend);
	POST_GOMP_loop_ordered_static_next(istart, iend);
}

bool GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_start, "GOMP_loop_ordered_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ordered_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_next, "GOMP_loop_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_runtime_next(istart, iend);
	lib_GOMP_loop_runtime_next(istart, iend);
	POST_GOMP_loop_runtime_next(istart, iend);
}

bool GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_start, "GOMP_loop_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	lib_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	POST_GOMP_loop_runtime_start(start, end, incr, istart, iend);
}

bool GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_next, "GOMP_loop_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_static_next(istart, iend);
	lib_GOMP_loop_static_next(istart, iend);
	POST_GOMP_loop_static_next(istart, iend);
}

bool GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_start, "GOMP_loop_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
}

void GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic, "GOMP_parallel_loop_dynamic");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_dynamic.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

void GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic_start, "GOMP_parallel_loop_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
	lib_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
	POST_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
}

void GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided, "GOMP_parallel_loop_guided");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_guided.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

void GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided_start, "GOMP_parallel_loop_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
	lib_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
	POST_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
}

void GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_dynamic, "GOMP_parallel_loop_nonmonotonic_dynamic");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_dynamic.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_nonmonotonic_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

void GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_guided, "GOMP_parallel_loop_nonmonotonic_guided");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_guided.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_nonmonotonic_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

void GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime, "GOMP_parallel_loop_runtime");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_runtime.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
	lib_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
	POST_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
}

void GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime_start, "GOMP_parallel_loop_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
	lib_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
	POST_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
}

void GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static, "GOMP_parallel_loop_static");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_static.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
	lib_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
	POST_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

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
/* loop_ull.c
/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_dynamic_start, "GOMP_loop_ull_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_dynamic_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_guided_start, "GOMP_loop_ull_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_guided_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_runtime_start, "GOMP_loop_ull_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
	lib_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
	POST_GOMP_loop_ull_doacross_runtime_start(ncounts, counts, istart, iend);
}

bool GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_static_start, "GOMP_loop_ull_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	lib_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
	POST_GOMP_loop_ull_doacross_static_start(ncounts, counts, chunk_size, istart, iend);
}

bool GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_next, "GOMP_loop_ull_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_dynamic_next(istart, iend);
	lib_GOMP_loop_ull_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_dynamic_next(istart, iend);
}

bool GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_start, "GOMP_loop_ull_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_next, "GOMP_loop_ull_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_guided_next(istart, iend);
	lib_GOMP_loop_ull_guided_next(istart, iend);
	POST_GOMP_loop_ull_guided_next(istart, iend);
}

bool GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_start, "GOMP_loop_ull_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_next, "GOMP_loop_ull_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
	lib_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_next(istart, iend);
}

bool GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_start, "GOMP_loop_ull_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_next, "GOMP_loop_ull_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
	lib_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_next(istart, iend);
}

bool GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_start, "GOMP_loop_ull_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_next, "GOMP_loop_ull_ordered_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	lib_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	POST_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
}

bool GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_start, "GOMP_loop_ull_ordered_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_next, "GOMP_loop_ull_ordered_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_guided_next(istart, iend);
	lib_GOMP_loop_ull_ordered_guided_next(istart, iend);
	POST_GOMP_loop_ull_ordered_guided_next(istart, iend);
}

bool GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_start, "GOMP_loop_ull_ordered_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_next, "GOMP_loop_ull_ordered_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	lib_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	POST_GOMP_loop_ull_ordered_runtime_next(istart, iend);
}

bool GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_start, "GOMP_loop_ull_ordered_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	lib_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	POST_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
}

bool GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_next, "GOMP_loop_ull_ordered_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_static_next(istart, iend);
	lib_GOMP_loop_ull_ordered_static_next(istart, iend);
	POST_GOMP_loop_ull_ordered_static_next(istart, iend);
}

bool GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_start, "GOMP_loop_ull_ordered_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_ordered_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
}

bool GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_next, "GOMP_loop_ull_runtime_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_runtime_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_runtime_next(istart, iend);
	lib_GOMP_loop_ull_runtime_next(istart, iend);
	POST_GOMP_loop_ull_runtime_next(istart, iend);
}

bool GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_start, "GOMP_loop_ull_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	lib_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	POST_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
}

bool GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_next, "GOMP_loop_ull_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_static_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_static_next(istart, iend);
	lib_GOMP_loop_ull_static_next(istart, iend);
	POST_GOMP_loop_ull_static_next(istart, iend);
}

bool GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_start, "GOMP_loop_ull_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	lib_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	POST_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
}

/* ------------------------------------------------------------- */
/* ordered.c
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

void GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_post, "GOMP_doacross_ull_post");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_post.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_post(counts);
	lib_GOMP_doacross_ull_post(counts);
	POST_GOMP_doacross_ull_post(counts);
}

void GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_wait, "GOMP_doacross_ull_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_wait(first);
	lib_GOMP_doacross_ull_wait(first);
	POST_GOMP_doacross_ull_wait(first);
}

void GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_wait, "GOMP_doacross_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_wait(first);
	lib_GOMP_doacross_wait(first);
	POST_GOMP_doacross_wait(first);
}

void GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_end, "GOMP_ordered_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_ordered_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_ordered_end();
	lib_GOMP_ordered_end();
	POST_GOMP_ordered_end();
}

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
/* parallel.c
/* ------------------------------------------------------------- */
bool GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_cancel, "GOMP_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_cancel(which, do_cancel);
	lib_GOMP_cancel(which, do_cancel);
	POST_GOMP_cancel(which, do_cancel);
}

bool GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_cancellation_point, "GOMP_cancellation_point");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_cancellation_point.\n", (unsigned long int)pthread_self());
	PRE_GOMP_cancellation_point(which);
	lib_GOMP_cancellation_point(which);
	POST_GOMP_cancellation_point(which);
}

void GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel, "GOMP_parallel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel(fn, data, num_threads, flags);
	lib_GOMP_parallel(fn, data, num_threads, flags);
	POST_GOMP_parallel(fn, data, num_threads, flags);
}

void GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_end, "GOMP_parallel_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_end();
	lib_GOMP_parallel_end();
	POST_GOMP_parallel_end();
}

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
/* sections.c
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

void GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections_start, "GOMP_parallel_sections_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_sections_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_sections_start(fn, data, num_threads, count);
	lib_GOMP_parallel_sections_start(fn, data, num_threads, count);
	POST_GOMP_parallel_sections_start(fn, data, num_threads, count);
}

void GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end, "GOMP_sections_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end();
	lib_GOMP_sections_end();
	POST_GOMP_sections_end();
}

bool GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_cancel, "GOMP_sections_end_cancel");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end_cancel.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end_cancel();
	lib_GOMP_sections_end_cancel();
	POST_GOMP_sections_end_cancel();
}

void GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_nowait, "GOMP_sections_end_nowait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_end_nowait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_end_nowait();
	lib_GOMP_sections_end_nowait();
	POST_GOMP_sections_end_nowait();
}

unsigned GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_next, "GOMP_sections_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_next();
	lib_GOMP_sections_next();
	POST_GOMP_sections_next();
}

unsigned GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_start, "GOMP_sections_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_sections_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_sections_start(count);
	lib_GOMP_sections_start(count);
	POST_GOMP_sections_start(count);
}

/* ------------------------------------------------------------- */
/* single.c
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

void *GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_start, "GOMP_single_copy_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_single_copy_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_single_copy_start();
	lib_GOMP_single_copy_start();
	POST_GOMP_single_copy_start();
}

bool GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_single_start, "GOMP_single_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_single_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_single_start();
	lib_GOMP_single_start();
	POST_GOMP_single_start();
}

/* ------------------------------------------------------------- */
/* task.c
/* ------------------------------------------------------------- */
void GOMP_PLUGIN_target_task_completion(void *data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_PLUGIN_target_task_completion, "GOMP_PLUGIN_target_task_completion");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_PLUGIN_target_task_completion.\n", (unsigned long int)pthread_self());
	PRE_GOMP_PLUGIN_target_task_completion(data);
	lib_GOMP_PLUGIN_target_task_completion(data);
	POST_GOMP_PLUGIN_target_task_completion(data);
}

void GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_task, "GOMP_task");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_task.\n", (unsigned long int)pthread_self());
	PRE_GOMP_task(fn, data, cpyfn, arg_size, arg_align, if_clause, flags, depend, priority);
	lib_GOMP_task(fn, data, cpyfn, arg_size, arg_align, if_clause, flags, depend, priority);
	POST_GOMP_task(fn, data, cpyfn, arg_size, arg_align, if_clause, flags, depend, priority);
}

void GOMP_taskgroup_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_end, "GOMP_taskgroup_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_taskgroup_end.\n", (unsigned long int)pthread_self());
	PRE_GOMP_taskgroup_end();
	lib_GOMP_taskgroup_end();
	POST_GOMP_taskgroup_end();
}

void GOMP_taskgroup_start(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_start, "GOMP_taskgroup_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_taskgroup_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_taskgroup_start();
	lib_GOMP_taskgroup_start();
	POST_GOMP_taskgroup_start();
}

void GOMP_taskwait(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_taskwait, "GOMP_taskwait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_taskwait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_taskwait();
	lib_GOMP_taskwait();
	POST_GOMP_taskwait();
}

void GOMP_taskyield(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_taskyield, "GOMP_taskyield");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_taskyield.\n", (unsigned long int)pthread_self());
	PRE_GOMP_taskyield();
	lib_GOMP_taskyield();
	POST_GOMP_taskyield();
}

/* ------------------------------------------------------------- */
/* target.c
/* ------------------------------------------------------------- */
void GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_register, "GOMP_offload_register");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_register.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_register(host_table, target_type, target_data);
	lib_GOMP_offload_register(host_table, target_type, target_data);
	POST_GOMP_offload_register(host_table, target_type, target_data);
}

void GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_register_ver, "GOMP_offload_register_ver");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_register_ver.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_register_ver(version, host_table, target_type, target_data);
	lib_GOMP_offload_register_ver(version, host_table, target_type, target_data);
	POST_GOMP_offload_register_ver(version, host_table, target_type, target_data);
}

void GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_unregister, "GOMP_offload_unregister");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_unregister.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_unregister(host_table, target_type, target_data);
	lib_GOMP_offload_unregister(host_table, target_type, target_data);
	POST_GOMP_offload_unregister(host_table, target_type, target_data);
}

void GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_unregister_ver, "GOMP_offload_unregister_ver");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_unregister_ver.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_unregister_ver(version, host_table, target_type, target_data);
	lib_GOMP_offload_unregister_ver(version, host_table, target_type, target_data);
	POST_GOMP_offload_unregister_ver(version, host_table, target_type, target_data);
}

void GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target, "GOMP_target");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target(device, fn, unused, mapnum, hostaddrs, sizes, kinds);
	lib_GOMP_target(device, fn, unused, mapnum, hostaddrs, sizes, kinds);
	POST_GOMP_target(device, fn, unused, mapnum, hostaddrs, sizes, kinds);
}

void GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_data, "GOMP_target_data");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_data.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_data(device, unused, mapnum, hostaddrs, sizes, kinds);
	lib_GOMP_target_data(device, unused, mapnum, hostaddrs, sizes, kinds);
	POST_GOMP_target_data(device, unused, mapnum, hostaddrs, sizes, kinds);
}

void GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_data_ext, "GOMP_target_data_ext");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_data_ext.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_data_ext(device, mapnum, hostaddrs, sizes, kinds);
	lib_GOMP_target_data_ext(device, mapnum, hostaddrs, sizes, kinds);
	POST_GOMP_target_data_ext(device, mapnum, hostaddrs, sizes, kinds);
}

void GOMP_target_end_data(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_end_data, "GOMP_target_end_data");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_end_data.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_end_data();
	lib_GOMP_target_end_data();
	POST_GOMP_target_end_data();
}

void GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_enter_exit_data, "GOMP_target_enter_exit_data");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_enter_exit_data.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
	lib_GOMP_target_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
	POST_GOMP_target_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
}

void GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_ext, "GOMP_target_ext");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_ext.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_ext(device, fn, mapnum, hostaddrs, sizes, kinds, flags, depend, args);
	lib_GOMP_target_ext(device, fn, mapnum, hostaddrs, sizes, kinds, flags, depend, args);
	POST_GOMP_target_ext(device, fn, mapnum, hostaddrs, sizes, kinds, flags, depend, args);
}

void GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_update, "GOMP_target_update");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_update.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_update(device, unused, mapnum, hostaddrs, sizes, kinds);
	lib_GOMP_target_update(device, unused, mapnum, hostaddrs, sizes, kinds);
	POST_GOMP_target_update(device, unused, mapnum, hostaddrs, sizes, kinds);
}

void GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_target_update_ext, "GOMP_target_update_ext");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_target_update_ext.\n", (unsigned long int)pthread_self());
	PRE_GOMP_target_update_ext(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
	lib_GOMP_target_update_ext(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
	POST_GOMP_target_update_ext(device, mapnum, hostaddrs, sizes, kinds, flags, depend);
}

void GOMP_teams(unsigned int num_teams, unsigned int thread_limit)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_teams, "GOMP_teams");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_teams.\n", (unsigned long int)pthread_self());
	PRE_GOMP_teams(num_teams, thread_limit);
	lib_GOMP_teams(num_teams, thread_limit);
	POST_GOMP_teams(num_teams, thread_limit);
}

/* ------------------------------------------------------------- */
/* taskloop.c
/* ------------------------------------------------------------- */
void GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_taskloop, "GOMP_taskloop");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_taskloop.\n", (unsigned long int)pthread_self());
	PRE_GOMP_taskloop(fn, data, cpyfn, arg_size, arg_align, flags, num_tasks, priority, start, end, step);
	lib_GOMP_taskloop(fn, data, cpyfn, arg_size, arg_align, flags, num_tasks, priority, start, end, step);
	POST_GOMP_taskloop(fn, data, cpyfn, arg_size, arg_align, flags, num_tasks, priority, start, end, step);
}

/* ------------------------------------------------------------- */
/* oacc-parallel.c
/* ------------------------------------------------------------- */
void GOACC_data_end(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_data_end, "GOACC_data_end");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_data_end.\n", (unsigned long int)pthread_self());
	PRE_GOACC_data_end();
	lib_GOACC_data_end();
	POST_GOACC_data_end();
}

void GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_data_start, "GOACC_data_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_data_start.\n", (unsigned long int)pthread_self());
	PRE_GOACC_data_start(device, mapnum, hostaddrs, sizes, kinds);
	lib_GOACC_data_start(device, mapnum, hostaddrs, sizes, kinds);
	POST_GOACC_data_start(device, mapnum, hostaddrs, sizes, kinds);
}

void GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_declare, "GOACC_declare");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_declare.\n", (unsigned long int)pthread_self());
	PRE_GOACC_declare(device, mapnum, hostaddrs, sizes, kinds);
	lib_GOACC_declare(device, mapnum, hostaddrs, sizes, kinds);
	POST_GOACC_declare(device, mapnum, hostaddrs, sizes, kinds);
}

void GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_enter_exit_data, "GOACC_enter_exit_data");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_enter_exit_data.\n", (unsigned long int)pthread_self());
	PRE_GOACC_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
	lib_GOACC_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
	POST_GOACC_enter_exit_data(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
}

int GOACC_get_num_threads(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_get_num_threads, "GOACC_get_num_threads");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_get_num_threads.\n", (unsigned long int)pthread_self());
	PRE_GOACC_get_num_threads();
	lib_GOACC_get_num_threads();
	POST_GOACC_get_num_threads();
}

int GOACC_get_thread_num(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_get_thread_num, "GOACC_get_thread_num");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_get_thread_num.\n", (unsigned long int)pthread_self());
	PRE_GOACC_get_thread_num();
	lib_GOACC_get_thread_num();
	POST_GOACC_get_thread_num();
}

void GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_parallel, "GOACC_parallel");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_parallel.\n", (unsigned long int)pthread_self());
	PRE_GOACC_parallel(device, fn, mapnum, hostaddrs, sizes, kinds, num_gangs, num_workers, vector_length, async, num_waits);
	lib_GOACC_parallel(device, fn, mapnum, hostaddrs, sizes, kinds, num_gangs, num_workers, vector_length, async, num_waits);
	POST_GOACC_parallel(device, fn, mapnum, hostaddrs, sizes, kinds, num_gangs, num_workers, vector_length, async, num_waits);
}

void GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_parallel_keyed, "GOACC_parallel_keyed");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_parallel_keyed.\n", (unsigned long int)pthread_self());
	PRE_GOACC_parallel_keyed(device, fn, mapnum, hostaddrs, sizes, kinds);
	lib_GOACC_parallel_keyed(device, fn, mapnum, hostaddrs, sizes, kinds);
	POST_GOACC_parallel_keyed(device, fn, mapnum, hostaddrs, sizes, kinds);
}

void GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_update, "GOACC_update");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_update.\n", (unsigned long int)pthread_self());
	PRE_GOACC_update(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
	lib_GOACC_update(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
	POST_GOACC_update(device, mapnum, hostaddrs, sizes, kinds, async, num_waits);
}

void GOACC_wait(int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOACC_wait, "GOACC_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOACC_wait.\n", (unsigned long int)pthread_self());
	PRE_GOACC_wait(async, num_waits);
	lib_GOACC_wait(async, num_waits);
	POST_GOACC_wait(async, num_waits);
}

///GENERATED 120 FUNCTIONS
