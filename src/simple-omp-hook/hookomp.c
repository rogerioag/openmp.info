/* 
	Todo (jorge):
		- conferir se está faltando/sobrando funções
		- corrigir nomes nos TRACEs

*/


#include "hookomp.h"

/* ------------------------------------------------------------- */
/* Test function.                                                */
void foo(void) {
	puts("Hello, I'm a shared library.\n");
}

/* ------------------------------------------------------------- */
/* barrier.c                                                     */
/* ------------------------------------------------------------- */
void GOMP_barrier (void) {
	PRINT_FUNC_NAME;
	
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier, "GOMP_barrier");

	TRACE("[hookomp]: Thread [%lu] is executing barrier.\n", (unsigned long int) pthread_self());

	TRACE("[GOMP_1.0] GOMP_barrier@GOMP_1.0.\n");
	PRE_GOMP_barrier();
	lib_GOMP_barrier();
	POST_GOMP_barrier();
}

/* ------------------------------------------------------------- */
bool GOMP_barrier_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier_cancel, "GOMP_barrier_cancel");
	TRACE("[GOMP_1.0] GOMP_barrier_cancel@GOMP_1.0.\n");
	
	PRE_GOMP_barrier_cancel();
	bool result = lib_GOMP_barrier_cancel();
	POST_GOMP_barrier_cancel();

	return result;
}

/* ------------------------------------------------------------- */
/* critical.c 													 */
/* ------------------------------------------------------------- */
void GOMP_critical_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_start, "GOMP_critical_start");
	TRACE("[GOMP_1.0] GOMP_critical_start@GOMP_1.0.\n");
	
	PRE_GOMP_critical_start();
	lib_GOMP_critical_start();
	POST_GOMP_critical_start();
}

/* ------------------------------------------------------------- */
void GOMP_critical_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_end, "GOMP_critical_end");
	TRACE("[GOMP_1.0] GOMP_critical_end@GOMP_1.0.\n");
	
		PRE_GOMP_critical_end();
	lib_GOMP_critical_end();
	POST_GOMP_critical_end();
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_start (void **pptr){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_start, "GOMP_critical_name_start");
	TRACE("[GOMP_1.0] GOMP_critical_name_start@GOMP_1.0.\n");
	
	PRE_GOMP_critical_name_start();
	lib_GOMP_critical_name_start(pptr);
	POST_GOMP_critical_name_start();
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_end (void **pptr){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_end, "GOMP_critical_name_end");
	TRACE("[GOMP_1.0] GOMP_critical_name_end@GOMP_1.0.\n");
	
	PRE_GOMP_critical_name_end();
	lib_GOMP_critical_name_end(pptr);
	POST_GOMP_critical_name_end();
}

/* ------------------------------------------------------------- */
void GOMP_atomic_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_start, "GOMP_atomic_start");
	TRACE("[GOMP_1.0] GOMP_atomic_start@GOMP_1.0.\n");
	
	PRE_GOMP_atomic_start();
	lib_GOMP_atomic_start();
	POST_GOMP_atomic_start();
}

/* ------------------------------------------------------------- */
void GOMP_atomic_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_end, "GOMP_atomic_end");
	TRACE("[GOMP_1.0] GOMP_atomic_end@GOMP_1.0.\n");
	
	PRE_GOMP_atomic_end();
	lib_GOMP_atomic_end();
	POST_GOMP_atomic_end();
}

/* ------------------------------------------------------------- */
/* loop.c                                                        */
/* ------------------------------------------------------------- */

void gomp_loop_init(struct gomp_work_share *ws, long start, long end, long incr, enum gomp_schedule_type sched, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_init, "gomp_loop_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_init();
	lib_gomp_loop_init(ws,start,end,incr,sched,chunk_size);
	POST_gomp_loop_init();
}


bool GOMP_loop_static_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_start, "GOMP_loop_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_static_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_static_start();
	bool result = lib_gomp_loop_static_start(start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_static_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_start (long start, long end, long incr, long chunk_size,
			 long *istart, long *iend){
	PRINT_FUNC_NAME;

	TRACE("Thread [%lu] is executing GOMP_loop_dynamic_start.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_start, "GOMP_loop_dynamic_start");

	PRE_GOMP_loop_dynamic_start();

	TRACE("[GOMP] GOMP_loop_dynamic_start@GOMP:[%p]\n", (void* )lib_GOMP_loop_dynamic_start);
	bool result = lib_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);

	POST_GOMP_loop_dynamic_start();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_start, "GOMP_loop_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_guided_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_guided_start();
	bool result = lib_gomp_loop_guided_start(start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_guided_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_start, "GOMP_loop_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_start();
	bool result = lib_GOMP_loop_nonmonotonic_dynamic_start(start,end,incr,chunk_size,istart,iend);
	POST_GOMP_loop_nonmonotonic_dynamic_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_start, "GOMP_loop_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_start();
	bool result = lib_GOMP_loop_nonmonotonic_guided_start(start,end,incr,chunk_size,istart,iend);
	POST_GOMP_loop_nonmonotonic_guided_start();
	return result;
}


/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_start (long start, long end, long incr,
			 long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_start, "GOMP_loop_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_runtime_start@GOMP_1.0.\n");
	
	PRE_GOMP_loop_runtime_start();
	bool result = lib_GOMP_loop_runtime_start(start,end,incr,istart,iend);
	POST_GOMP_loop_runtime_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_start, "GOMP_loop_ordered_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_static_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_static_start();
	bool result = lib_gomp_loop_ordered_static_start(start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ordered_static_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_start (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_start, "GOMP_loop_ordered_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_dynamic_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_dynamic_start();
	bool result = lib_gomp_loop_ordered_dynamic_start(start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ordered_dynamic_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_start, "GOMP_loop_ordered_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_guided_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_guided_start();
	bool result = lib_gomp_loop_ordered_guided_start(start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ordered_guided_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_static_start, "GOMP_loop_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_static_start();
	bool result = lib_GOMP_loop_doacross_static_start(ncounts,counts,chunk_size,istart,iend);
	POST_GOMP_loop_doacross_static_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_dynamic_start, "GOMP_loop_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_dynamic_start();
	bool result = lib_GOMP_loop_doacross_dynamic_start(ncounts,counts,chunk_size,istart,iend);
	POST_GOMP_loop_doacross_dynamic_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_guided_start, "GOMP_loop_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_guided_start();
	bool result = lib_GOMP_loop_doacross_guided_start(ncounts,counts,chunk_size,istart,iend);
	POST_GOMP_loop_doacross_guided_start();
	return result;
}


/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_start (long start, long end, long incr,
				 long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_start, "GOMP_loop_ordered_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_runtime_start@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ordered_runtime_start();
	bool result = lib_GOMP_loop_ordered_runtime_start(start,end,incr,istart,iend);
	POST_GOMP_loop_ordered_runtime_start();

	return result;
}

/* ------------------------------------------------------------- */
bool gomp_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_doacross_static_start, "gomp_loop_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_doacross_static_start();
	bool result = lib_gomp_loop_doacross_static_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_doacross_static_start();
	return result;
}

/* ------------------------------------------------------------- */
bool gomp_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_doacross_dynamic_start, "gomp_loop_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_doacross_dynamic_start();
	bool result = lib_gomp_loop_doacross_dynamic_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_doacross_dynamic_start();
	return result;
}

/* ------------------------------------------------------------- */
bool gomp_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_doacross_guided_start, "gomp_loop_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_doacross_guided_start();
	bool result = lib_gomp_loop_doacross_guided_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_doacross_guided_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_doacross_runtime_start, "GOMP_loop_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_doacross_runtime_start();
	bool result = lib_GOMP_loop_doacross_runtime_start(ncounts,counts,istart,iend);
	POST_GOMP_loop_doacross_runtime_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_static_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_next, "GOMP_loop_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_static_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_static_next();
	bool result = lib_gomp_loop_static_next(istart,iend);
	POST_gomp_loop_static_next();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	TRACE("Thread [%lu] is executing GOMP_loop_dynamic_next.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_next, "GOMP_loop_dynamic_next");
	
	PRE_GOMP_loop_dynamic_next();

	TRACE("[GOMP] GOMP_loop_dynamic_next@GOMP:[%p]\n", (void* )lib_GOMP_loop_dynamic_next);
	
	bool result = lib_GOMP_loop_dynamic_next(istart, iend);

	POST_GOMP_loop_dynamic_next(*istart, *iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_next, "GOMP_loop_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_guided_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_guided_next();
	bool result = lib_gomp_loop_guided_next(istart,iend);
	POST_gomp_loop_guided_next();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_next, "GOMP_loop_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_runtime_next@GOMP_1.0.\n");

	long int thread_executing_function_next = (long int) pthread_self();

	TRACE("[hookomp]: Thread [%lu] is calling %s.\n", thread_executing_function_next, __FUNCTION__);

	TRACE("[hookomp]: [After]-> GOMP_loop_runtime_next -- Tid[%lu] istart: %ld iend: %ld.\n", thread_executing_function_next, *istart, *iend);

	PRE_GOMP_loop_runtime_next();
	bool result = lib_GOMP_loop_runtime_next(istart,iend);
	POST_GOMP_loop_runtime_next();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_dynamic_next, "GOMP_loop_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_dynamic_next();
	bool result = lib_GOMP_loop_nonmonotonic_dynamic_next(istart,iend);
	POST_GOMP_loop_nonmonotonic_dynamic_next();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_nonmonotonic_guided_next, "GOMP_loop_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_nonmonotonic_guided_next();
	bool result = lib_GOMP_loop_nonmonotonic_guided_next(istart,iend);
	POST_GOMP_loop_nonmonotonic_guided_next();
	return result;
}


/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_next, "GOMP_loop_ordered_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_static_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_static_next();
	bool result = lib_gomp_loop_ordered_static_next(istart,iend);
	POST_gomp_loop_ordered_static_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_next, "GOMP_loop_ordered_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_dynamic_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_dynamic_next();
	bool result = lib_gomp_loop_ordered_dynamic_next(istart,iend);
	POST_gomp_loop_ordered_dynamic_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_next, "GOMP_loop_ordered_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_guided_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_ordered_guided_next();
	bool result = lib_gomp_loop_ordered_guided_next(istart,iend);
	POST_gomp_loop_ordered_guided_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_next, "GOMP_loop_ordered_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_runtime_next@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ordered_runtime_next();
	bool result = lib_GOMP_loop_ordered_runtime_next(istart,iend);
	POST_GOMP_loop_ordered_runtime_next();

	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static_start, "GOMP_parallel_loop_static_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_static_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_static_start[%p]\n", (void* )lib_GOMP_parallel_loop_static_start);

		PRE_GOMP_parallel_loop_static_start();
	lib_GOMP_parallel_loop_static_start(fn,data,num_threads,start,end,incr,chunk_size);
	POST_GOMP_parallel_loop_static_start();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic_start, "GOMP_parallel_loop_dynamic_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_dynamic_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_dynamic_start[%p]\n", (void* )lib_GOMP_parallel_loop_dynamic_start);

		PRE_GOMP_parallel_loop_dynamic_start();
	lib_GOMP_parallel_loop_dynamic_start(fn,data,num_threads,start,end,incr,chunk_size);
	POST_GOMP_parallel_loop_dynamic_start();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided_start, "GOMP_parallel_loop_guided_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_guided_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_guided_start[%p]\n", (void* )lib_GOMP_parallel_loop_guided_start);

		PRE_GOMP_parallel_loop_guided_start();
	lib_GOMP_parallel_loop_guided_start(fn,data,num_threads,start,end,incr,chunk_size);
	POST_GOMP_parallel_loop_guided_start();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime_start, "GOMP_parallel_loop_runtime_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_runtime_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_runtime_start[%p]\n", (void* )lib_GOMP_parallel_loop_runtime_start);

		PRE_GOMP_parallel_loop_runtime_start();
	lib_GOMP_parallel_loop_runtime_start(fn,data,num_threads,start,end,incr);
	POST_GOMP_parallel_loop_runtime_start();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static (void (*fn) (void *), void *data,
			   unsigned num_threads, long start, long end,
			   long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static, "GOMP_parallel_loop_static");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_static[%p]\n", (void* )lib_GOMP_parallel_loop_static);

		PRE_GOMP_parallel_loop_static();
	lib_GOMP_parallel_loop_static(fn,data,num_threads,start,end,incr,chunk_size,flags);
	POST_GOMP_parallel_loop_static();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic, "GOMP_parallel_loop_dynamic");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_dynamic[%p]\n", (void* )lib_GOMP_parallel_loop_dynamic);

		PRE_GOMP_parallel_loop_dynamic();
	lib_GOMP_parallel_loop_dynamic(fn,data,num_threads,start,end,incr,chunk_size,flags);
	POST_GOMP_parallel_loop_dynamic();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided, "GOMP_parallel_loop_guided");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_guided[%p]\n", (void* )lib_GOMP_parallel_loop_guided);

		PRE_GOMP_parallel_loop_guided();
	lib_GOMP_parallel_loop_guided(fn,data,num_threads,start,end,incr,chunk_size,flags);
	POST_GOMP_parallel_loop_guided();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_dynamic, "GOMP_parallel_loop_nonmonotonic_dynamic");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_dynamic.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_dynamic();
	lib_GOMP_parallel_loop_nonmonotonic_dynamic(fn,data,num_threads,start,end,incr,chunk_size,flags);
	POST_GOMP_parallel_loop_nonmonotonic_dynamic();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_nonmonotonic_guided, "GOMP_parallel_loop_nonmonotonic_guided");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_parallel_loop_nonmonotonic_guided.\n", (unsigned long int)pthread_self());
	PRE_GOMP_parallel_loop_nonmonotonic_guided();
	lib_GOMP_parallel_loop_nonmonotonic_guided(fn,data,num_threads,start,end,incr,chunk_size,flags);
	POST_GOMP_parallel_loop_nonmonotonic_guided();
}


/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime, "GOMP_parallel_loop_runtime");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_runtime[%p]\n", (void* )lib_GOMP_parallel_loop_runtime);

	PRE_GOMP_parallel_loop_runtime();
	lib_GOMP_parallel_loop_runtime(fn,data,num_threads,start,end,incr,flags);
	POST_GOMP_parallel_loop_runtime();
}

/* ------------------------------------------------------------- */
void GOMP_loop_end (void){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end, "GOMP_loop_end");

	TRACE("[GOMP_1.0] lib_GOMP_loop_end[%p]\n", (void* )lib_GOMP_loop_end);

	PRE_GOMP_loop_end();
	lib_GOMP_loop_end();
	POST_GOMP_loop_end();
}
/* ------------------------------------------------------------- */
void GOMP_loop_end_nowait (void){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_nowait, "GOMP_loop_end_nowait");

	TRACE("[GOMP_1.0] lib_GOMP_loop_end_nowait[%p]\n", (void* )GOMP_loop_end_nowait);

	TRACE("[hookomp]: Thread [%lu] is calling %s.\n", (long int) pthread_self(), __FUNCTION__);

	PRE_GOMP_loop_end_nowait();
	lib_GOMP_loop_end_nowait();
	POST_GOMP_loop_end_nowait();
}

/* ------------------------------------------------------------- */
bool GOMP_loop_end_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_cancel, "GOMP_loop_end_cancel");
	TRACE("[GOMP_1.0] GOMP_loop_end_cancel@GOMP_1.0.\n");
	
	PRE_GOMP_loop_end_cancel();
	bool result = lib_GOMP_loop_end_cancel();
	POST_GOMP_loop_end_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
/* loop_ull.c                                                    */
/* ------------------------------------------------------------- */

void gomp_loop_ull_init(struct gomp_work_share *ws, bool up, gomp_ull start, gomp_ull end, gomp_ull incr, enum gomp_schedule_type sched, gomp_ull chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_ull_init, "gomp_loop_ull_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_ull_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_ull_init();
	lib_gomp_loop_ull_init(ws,up,start,end,incr,sched,chunk_size);
	POST_gomp_loop_ull_init();
}

bool GOMP_loop_ull_static_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_start, "GOMP_loop_ull_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_static_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_static_start();
	bool result = lib_gomp_loop_ull_static_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_static_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long chunk_size,
			     unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_start, "GOMP_loop_ull_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_dynamic_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_dynamic_start();
	bool result = lib_gomp_loop_ull_dynamic_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_dynamic_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_start, "GOMP_loop_ull_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_guided_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_guided_start();
	bool result = lib_gomp_loop_ull_guided_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_guided_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_start, "GOMP_loop_ull_nonmonotonic_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_start();
	bool result = lib_GOMP_loop_ull_nonmonotonic_dynamic_start(up,start,end,incr,chunk_size,istart,iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_start, "GOMP_loop_ull_nonmonotonic_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_start();
	bool result = lib_GOMP_loop_ull_nonmonotonic_guided_start(up,start,end,incr,chunk_size,istart,iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_start();
	return result;
}



/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_start, "GOMP_loop_ull_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_runtime_start@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ull_runtime_start();
	bool result = lib_GOMP_loop_ull_runtime_start(up,start,end,incr,istart,iend);
	POST_GOMP_loop_ull_runtime_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_start, "GOMP_loop_ull_ordered_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_static_start@GOMP_1.0.\n");
	
		PRE_gomp_loop_ull_ordered_static_start();
	bool result = lib_gomp_loop_ull_ordered_static_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_ordered_static_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long chunk_size,
				     unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_start, "GOMP_loop_ull_ordered_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_dynamic_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_ordered_dynamic_start();
	bool result = lib_gomp_loop_ull_ordered_dynamic_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_ordered_dynamic_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_start, "GOMP_loop_ull_ordered_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_guided_start@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_ordered_guided_start();
	bool result = lib_gomp_loop_ull_ordered_guided_start(up,start,end,incr,chunk_size,istart,iend);
	POST_gomp_loop_ull_ordered_guided_start();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long *istart,
				     unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_start, "GOMP_loop_ull_ordered_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_runtime_start@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ull_ordered_runtime_start();
	bool result = lib_GOMP_loop_ull_ordered_runtime_start(up,start,end,incr,istart,iend);
	POST_GOMP_loop_ull_ordered_runtime_start();

	return result;
}


/* ------------------------------------------------------------- */
bool gomp_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_ull_doacross_static_start, "gomp_loop_ull_doacross_static_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_ull_doacross_static_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_ull_doacross_static_start();
	bool result = lib_gomp_loop_ull_doacross_static_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_ull_doacross_static_start();
	return result;
}

/* ------------------------------------------------------------- */
bool gomp_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_ull_doacross_dynamic_start, "gomp_loop_ull_doacross_dynamic_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_ull_doacross_dynamic_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_ull_doacross_dynamic_start();
	bool result = lib_gomp_loop_ull_doacross_dynamic_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_ull_doacross_dynamic_start();
	return result;
}

/* ------------------------------------------------------------- */
bool gomp_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_loop_ull_doacross_guided_start, "gomp_loop_ull_doacross_guided_start");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_loop_ull_doacross_guided_start.\n", (unsigned long int)pthread_self());
	PRE_gomp_loop_ull_doacross_guided_start();
	bool result = lib_gomp_loop_ull_doacross_guided_start(ncounts,counts,chunk_size,istart,iend);
	POST_gomp_loop_ull_doacross_guided_start();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_doacross_runtime_start, "GOMP_loop_ull_doacross_runtime_start");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_doacross_runtime_start.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_doacross_runtime_start();
	bool result = lib_GOMP_loop_ull_doacross_runtime_start(ncounts,counts,istart,iend);
	POST_GOMP_loop_ull_doacross_runtime_start();
	return result;
}


/* ------------------------------------------------------------- */
bool GOMP_loop_ull_static_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_next, "GOMP_loop_ull_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_static_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_static_next();
	bool result = lib_gomp_loop_ull_static_next(istart,iend);
	POST_gomp_loop_ull_static_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_next, "GOMP_loop_ull_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_dynamic_next@GOMP_1.0.\n");
	
PRE_gomp_loop_ull_dynamic_next();
	bool result = lib_gomp_loop_ull_dynamic_next(istart,iend);
	POST_gomp_loop_ull_dynamic_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_next, "GOMP_loop_ull_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_guided_next@GOMP_1.0.\n");
	
PRE_gomp_loop_ull_guided_next();
	bool result = lib_gomp_loop_ull_guided_next(istart,iend);
	POST_gomp_loop_ull_guided_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_dynamic_next, "GOMP_loop_ull_nonmonotonic_dynamic_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_dynamic_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_dynamic_next();
	bool result = lib_GOMP_loop_ull_nonmonotonic_dynamic_next(istart,iend);
	POST_GOMP_loop_ull_nonmonotonic_dynamic_next();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_nonmonotonic_guided_next, "GOMP_loop_ull_nonmonotonic_guided_next");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_loop_ull_nonmonotonic_guided_next.\n", (unsigned long int)pthread_self());
	PRE_GOMP_loop_ull_nonmonotonic_guided_next();
	bool result = lib_GOMP_loop_ull_nonmonotonic_guided_next(istart,iend);
	POST_GOMP_loop_ull_nonmonotonic_guided_next();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_next, "GOMP_loop_ull_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_runtime_next@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ull_runtime_next();
	bool result = lib_GOMP_loop_ull_runtime_next(istart,iend);
	POST_GOMP_loop_ull_runtime_next();

	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_next, "GOMP_loop_ull_ordered_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_static_next@GOMP_1.0.\n");
	
	PRE_gomp_loop_ull_ordered_static_next();
	bool result = lib_gomp_loop_ull_ordered_static_next(istart,iend);
	POST_gomp_loop_ull_ordered_static_next();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_next, "GOMP_loop_ull_ordered_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_dynamic_next@GOMP_1.0.\n");
	PRE_gomp_loop_ull_ordered_dynamic_next();
	bool result = lib_gomp_loop_ull_ordered_dynamic_next(istart,iend);
	POST_gomp_loop_ull_ordered_dynamic_next();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_next, "GOMP_loop_ull_ordered_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_guided_next@GOMP_1.0.\n");
	
PRE_gomp_loop_ull_ordered_guided_next();
	bool result = lib_gomp_loop_ull_ordered_guided_next(istart,iend);
	POST_gomp_loop_ull_ordered_guided_next();
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_next, "GOMP_loop_ull_ordered_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_runtime_next@GOMP_1.0.\n");
	
	PRE_GOMP_loop_ull_ordered_runtime_next();
	bool result = lib_GOMP_loop_ull_ordered_runtime_next(istart,iend);
	POST_GOMP_loop_ull_ordered_runtime_next();
	return result;
}

/* ------------------------------------------------------------- */
/* ordered.c                                                     */
/* ------------------------------------------------------------- */

void gomp_ordered_first(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_first, "gomp_ordered_first");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_first.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_first();
	lib_gomp_ordered_first();
	POST_gomp_ordered_first();
}

/* ------------------------------------------------------------- */
void gomp_ordered_last(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_last, "gomp_ordered_last");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_last.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_last();
	lib_gomp_ordered_last();
	POST_gomp_ordered_last();
}

/* ------------------------------------------------------------- */
void gomp_ordered_next(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_next, "gomp_ordered_next");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_next.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_next();
	lib_gomp_ordered_next();
	POST_gomp_ordered_next();
}

/* ------------------------------------------------------------- */
void gomp_ordered_static_init(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_static_init, "gomp_ordered_static_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_static_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_static_init();
	lib_gomp_ordered_static_init();
	POST_gomp_ordered_static_init();
}

/* ------------------------------------------------------------- */
void gomp_ordered_static_next(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_static_next, "gomp_ordered_static_next");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_static_next.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_static_next();
	lib_gomp_ordered_static_next();
	POST_gomp_ordered_static_next();
}

/* ------------------------------------------------------------- */
void gomp_ordered_sync(void)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_ordered_sync, "gomp_ordered_sync");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_ordered_sync.\n", (unsigned long int)pthread_self());
	PRE_gomp_ordered_sync();
	lib_gomp_ordered_sync();
	POST_gomp_ordered_sync();
}


void GOMP_ordered_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_start, "GOMP_ordered_start");
	TRACE("[GOMP_1.0] GOMP_ordered_start@GOMP_1.0.\n");
	
PRE_GOMP_ordered_start();
	lib_GOMP_ordered_start();
	POST_GOMP_ordered_start();
}

/* ------------------------------------------------------------- */
void GOMP_ordered_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_end, "GOMP_ordered_end");
	TRACE("[GOMP_1.0] GOMP_ordered_end@GOMP_1.0.\n");
	
	PRE_GOMP_ordered_end();
	lib_GOMP_ordered_end();
	POST_GOMP_ordered_end();
}

/* ------------------------------------------------------------- */
void gomp_doacross_init(unsigned ncounts, long *counts, long chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_doacross_init, "gomp_doacross_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_doacross_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_doacross_init();
	lib_gomp_doacross_init(ncounts,counts,chunk_size);
	POST_gomp_doacross_init();
}

/* ------------------------------------------------------------- */
void GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_post, "GOMP_doacross_post");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_post.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_post();
	lib_GOMP_doacross_post(counts);
	POST_GOMP_doacross_post();
}

/* ------------------------------------------------------------- */
void GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_wait, "GOMP_doacross_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_wait();
	lib_GOMP_doacross_wait(first);
	POST_GOMP_doacross_wait();
}

/* ------------------------------------------------------------- */
void gomp_doacross_ull_init(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_doacross_ull_init, "gomp_doacross_ull_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_doacross_ull_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_doacross_ull_init();
	lib_gomp_doacross_ull_init(ncounts,counts,chunk_size);
	POST_gomp_doacross_ull_init();
}

/* ------------------------------------------------------------- */
void GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_post, "GOMP_doacross_ull_post");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_post.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_post();
	lib_GOMP_doacross_ull_post(counts);
	POST_GOMP_doacross_ull_post();
}

/* ------------------------------------------------------------- */
void GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_doacross_ull_wait, "GOMP_doacross_ull_wait");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_doacross_ull_wait.\n", (unsigned long int)pthread_self());
	PRE_GOMP_doacross_ull_wait();
	lib_GOMP_doacross_ull_wait(first);
	POST_GOMP_doacross_ull_wait();
}

/* ------------------------------------------------------------- */
/* parallel.c                                                    */
/* ------------------------------------------------------------- */
/* Function to intercept GOMP_parallel_start                     */
void GOMP_parallel_start (void (*fn) (void *), void *data, unsigned num_threads){
	PRINT_FUNC_NAME;

	TRACE("Thread [%lu] is executing GOMP_parallel_start.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_start, "GOMP_parallel_start");

	PRE_GOMP_parallel_start();

	TRACE("[GOMP] lib_GOMP_parallel_start@GOMP:[%p]\n", (void* )lib_GOMP_parallel_start);
	lib_GOMP_parallel_start(fn, data, num_threads);

	POST_GOMP_parallel_start();
}

/* ------------------------------------------------------------- */
/* Function to intercept GOMP_parallel_end                       */
void GOMP_parallel_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_end, "GOMP_parallel_end");

	PRE_GOMP_parallel_end();

	TRACE("[GOMP] GOMP_parallel_end@GOMP:[%p]\n", (void* )lib_GOMP_parallel_end);
    lib_GOMP_parallel_end();

    POST_GOMP_parallel_end();
}

/* ------------------------------------------------------------- */
void GOMP_parallel (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel, "GOMP_parallel");

	TRACE("[GOMP_1.0] GOMP_parallel@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel[%p]\n", (void* )lib_GOMP_parallel);

	PRE_GOMP_parallel();
	lib_GOMP_parallel(fn,data,num_threads,flags);
	POST_GOMP_parallel();
}

/* ------------------------------------------------------------- */
bool GOMP_cancel (int which, bool do_cancel){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_cancel, "GOMP_cancel");
	TRACE("[GOMP_1.0] GOMP_cancel@GOMP_1.0.\n");
	
	PRE_GOMP_cancel();
	bool result = lib_GOMP_cancel(which,do_cancel);
	POST_GOMP_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_cancellation_point (int which){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_cancellation_point, "GOMP_cancellation_point");
	TRACE("[GOMP_1.0] GOMP_cancellation_point@GOMP_1.0.\n");
	
		PRE_GOMP_cancellation_point();
	bool result = lib_GOMP_cancellation_point(which);
	POST_GOMP_cancellation_point();
	
	return result;
}

/* ------------------------------------------------------------- */
/* task.c */
/* ------------------------------------------------------------- */
void GOMP_task (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *),
	   long arg_size, long arg_align, bool if_clause, unsigned flags,
	   void **depend){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_task, "GOMP_task");

	TRACE("[GOMP_1.0] GOMP_task@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_task[%p]\n", (void* )lib_GOMP_task);

	PRE_GOMP_task();

	lib_GOMP_task(fn, data, cpyfn, arg_size, arg_align, if_clause, flags, depend);

	POST_GOMP_task();
}

/* ------------------------------------------------------------- */
void GOMP_taskwait (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskwait, "GOMP_taskwait");
	TRACE("[GOMP_1.0] GOMP_taskwait@GOMP_1.0.\n");
	
	PRE_GOMP_taskwait();
	lib_GOMP_taskwait();
	POST_GOMP_taskwait();
}

/* ------------------------------------------------------------- */
void GOMP_taskyield (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskyield, "GOMP_taskyield");
	TRACE("[GOMP_1.0] GOMP_taskyield@GOMP_1.0.\n");
	
PRE_GOMP_taskyield();
	lib_GOMP_taskyield();
	POST_GOMP_taskyield();
}

/* ------------------------------------------------------------- */
void GOMP_taskgroup_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_start, "GOMP_taskgroup_start");
	TRACE("[GOMP_1.0] GOMP_taskgroup_start@GOMP_1.0.\n");
	PRE_GOMP_taskgroup_start();
	lib_GOMP_taskgroup_start();
	POST_GOMP_taskgroup_start();
}

/* ------------------------------------------------------------- */
void GOMP_taskgroup_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_end, "GOMP_taskgroup_end");
	TRACE("[GOMP_1.0] GOMP_taskgroup_end@GOMP_1.0.\n");
	
		PRE_GOMP_taskgroup_end();
	lib_GOMP_taskgroup_end();
	POST_GOMP_taskgroup_end();
}

/* ------------------------------------------------------------- */
/* sections.c */
/* ------------------------------------------------------------- */

void gomp_sections_init(struct gomp_work_share *ws, unsigned count)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_gomp_sections_init, "gomp_sections_init");
	TRACE("[hookomp]: Thread [%lu] is executing gomp_sections_init.\n", (unsigned long int)pthread_self());
	PRE_gomp_sections_init();
	lib_gomp_sections_init(ws,count);
	POST_gomp_sections_init();
}

unsigned GOMP_sections_start (unsigned count){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_start, "GOMP_sections_start");
	TRACE("[GOMP_1.0] GOMP_sections_start@GOMP_1.0.\n");
	
	PRE_GOMP_sections_start();
	unsigned result = lib_GOMP_sections_start(count);
	POST_GOMP_sections_start();
	
	return result;
}

/* ------------------------------------------------------------- */
unsigned GOMP_sections_next (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_next, "GOMP_sections_next");
	TRACE("[GOMP_1.0] GOMP_sections_next@GOMP_1.0.\n");
	
	PRE_GOMP_sections_next();
	unsigned result = lib_GOMP_sections_next();
	POST_GOMP_sections_next();
	
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections_start (void (*fn) (void *), void *data,
			      unsigned num_threads, unsigned count){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections_start, "GOMP_parallel_sections_start");

	TRACE("[GOMP_1.0] GOMP_parallel_sections_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_sections_start[%p]\n", (void* )lib_GOMP_parallel_sections_start);

	PRE_GOMP_parallel_sections_start();
	lib_GOMP_parallel_sections_start(fn,data,num_threads,count);
	POST_GOMP_parallel_sections_start();
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections (void (*fn) (void *), void *data,
			unsigned num_threads, unsigned count, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections, "GOMP_parallel_sections");

	TRACE("[GOMP_1.0] GOMP_parallel_sections@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GGOMP_parallel_sections[%p]\n", (void* )lib_GOMP_parallel_sections);

	PRE_GOMP_parallel_sections();
	lib_GOMP_parallel_sections(fn,data,num_threads,count,flags);
	POST_GOMP_parallel_sections();
}

/* ------------------------------------------------------------- */
void GOMP_sections_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end, "GOMP_sections_end");
	TRACE("[GOMP_1.0] GOMP_sections_end@GOMP_1.0.\n");
	
		PRE_GOMP_sections_end();
	lib_GOMP_sections_end();
	POST_GOMP_sections_end();
}
	
/* ------------------------------------------------------------- */
void GOMP_sections_end_nowait (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_nowait, "GOMP_sections_end_nowait");
	TRACE("[GOMP_1.0] GOMP_sections_end_nowait@GOMP_1.0.\n");
	PRE_GOMP_sections_end_nowait();
	lib_GOMP_sections_end_nowait();
	POST_GOMP_sections_end_nowait();
}
	
/* ------------------------------------------------------------- */
bool GOMP_sections_end_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_cancel, "GOMP_sections_end_cancel");
	TRACE("[GOMP_1.0] GOMP_sections_end_cancel@GOMP_1.0.\n");
	
	PRE_GOMP_sections_end_cancel();
	bool result = lib_GOMP_sections_end_cancel();
	POST_GOMP_sections_end_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
/* single.c */
/* ------------------------------------------------------------- */
bool GOMP_single_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_start, "GOMP_single_start");
	
   TRACE("[hookomp]: Testing single start[%lu].\n", (unsigned long int) pthread_self());

   TRACE("[GOMP_1.0] GOMP_single_start@GOMP_1.0.\n");
	PRE_GOMP_single_start();
	bool result = lib_GOMP_single_start();
	POST_GOMP_single_start();

   return result;
}

/* ------------------------------------------------------------- */
void *GOMP_single_copy_start (void){
	PRINT_FUNC_NAME;

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_start, "GOMP_single_copy_start");
	TRACE("[GOMP_1.0] GOMP_single_copy_start@GOMP_1.0.\n");
	
	void *result;
PRE_GOMP_single_copy_start();
	result = lib_GOMP_single_copy_start();
POST_GOMP_single_copy_start();
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_single_copy_end (void *data){

	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_end, "GOMP_single_copy_end");
	TRACE("[GOMP_1.0] GOMP_single_copy_end@GOMP_1.0.\n");
	
		PRE_GOMP_single_copy_end();
	lib_GOMP_single_copy_end(data);
	POST_GOMP_single_copy_end();
}

/* ------------------------------------------------------------- */
/* target.c */
/* ------------------------------------------------------------- */

void GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_register_ver, "GOMP_offload_register_ver");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_register_ver.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_register_ver();
	lib_GOMP_offload_register_ver(version,host_table,target_type,target_data);
	POST_GOMP_offload_register_ver();
}

/* ------------------------------------------------------------- */
void GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_register, "GOMP_offload_register");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_register.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_register();
	lib_GOMP_offload_register(host_table,target_type,target_data);
	POST_GOMP_offload_register();
}

/* ------------------------------------------------------------- */
void GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_unregister_ver, "GOMP_offload_unregister_ver");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_unregister_ver.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_unregister_ver();
	lib_GOMP_offload_unregister_ver(version,host_table,target_type,target_data);
	POST_GOMP_offload_unregister_ver();
}

/* ------------------------------------------------------------- */
void GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	GET_RUNTIME_FUNCTION(lib_GOMP_offload_unregister, "GOMP_offload_unregister");
	TRACE("[hookomp]: Thread [%lu] is executing GOMP_offload_unregister.\n", (unsigned long int)pthread_self());
	PRE_GOMP_offload_unregister();
	lib_GOMP_offload_unregister(host_table,target_type,target_data);
	POST_GOMP_offload_unregister();
}


void GOMP_target (int device, void (*fn) (void *), const void *unused,
	     size_t mapnum, void **hostaddrs, size_t *sizes,
	     unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target, "GOMP_target");
	TRACE("[GOMP_1.0] GOMP_target@GOMP_1.0.\n");
	
		PRE_GOMP_target();
	lib_GOMP_target(device,fn,unused,mapnum,hostaddrs,sizes,kinds);
	POST_GOMP_target();
}

/* ------------------------------------------------------------- */
void GOMP_target_data (int device, const void *unused, size_t mapnum,
		  void **hostaddrs, size_t *sizes, unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_data, "GOMP_target_data");
	TRACE("[GOMP_1.0] GOMP_target_data@GOMP_1.0.\n");
	
		PRE_GOMP_target_data();
	lib_GOMP_target_data(device,unused,mapnum,hostaddrs,sizes,kinds);
	POST_GOMP_target_data();
}

/* ------------------------------------------------------------- */
void GOMP_target_end_data (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_end_data, "GOMP_target_end_data");
	TRACE("[GOMP_1.0] GOMP_target_end_data@GOMP_1.0.\n");
	
	PRE_GOMP_target_end_data();
	lib_GOMP_target_end_data();
	POST_GOMP_target_end_data();
}

/* ------------------------------------------------------------- */
void GOMP_target_update (int device, const void *unused, size_t mapnum,
		    void **hostaddrs, size_t *sizes, unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_update, "GOMP_target_update");
	TRACE("[GOMP_1.0] GOMP_target_update@GOMP_1.0.\n");
	
	PRE_GOMP_target_update();
	lib_GOMP_target_update(device,unused,mapnum,hostaddrs,sizes,kinds);
	POST_GOMP_target_update();
}

/* ------------------------------------------------------------- */
void GOMP_teams (unsigned int num_teams, unsigned int thread_limit){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_teams, "GOMP_teams");
	TRACE("[GOMP_1.0] GOMP_teams@GOMP_1.0.\n");
	
		PRE_GOMP_teams();
	lib_GOMP_teams(num_teams,thread_limit);
	POST_GOMP_teams();
}

/* ------------------------------------------------------------- */
