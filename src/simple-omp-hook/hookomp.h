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

/* barrier.c */

void (*lib_GOMP_barrier)(void);
bool (*lib_GOMP_barrier_cancel)(void);

/* critical.c */

void (*lib_GOMP_critical_start)(void);
void (*lib_GOMP_critical_end)(void);
void (*lib_GOMP_critical_name_start)(void **pptr);
void (*lib_GOMP_critical_name_end)(void **pptr);

/* loop.c */

bool (*lib_GOMP_loop_runtime_start)(long start, long end, long incr, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_runtime_start)(long start, long end, long incr, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_runtime_start)(unsigned ncounts, long *counts, long *istart, long *iend);
bool (*lib_GOMP_loop_runtime_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_runtime_next)(long *istart, long *iend);
void (*lib_GOMP_parallel_loop_static_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
void (*lib_GOMP_parallel_loop_dynamic_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
void (*lib_GOMP_parallel_loop_guided_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
void (*lib_GOMP_parallel_loop_runtime_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
void (*lib_GOMP_parallel_loop_static)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_dynamic)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_guided)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_nonmonotonic_dynamic)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_nonmonotonic_guided)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_runtime)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
void (*lib_GOMP_loop_end)(void);
bool (*lib_GOMP_loop_end_cancel)(void);
void (*lib_GOMP_loop_end_nowait)(void);
bool (*lib_GOMP_loop_static_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_static_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_static_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_dynamic_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_guided_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_static_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_guided_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_guided_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_static_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_guided_next)(long *istart, long *iend);

/* loop_ull.c */

bool (*lib_GOMP_loop_ull_runtime_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_runtime_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_runtime_start)(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_runtime_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_runtime_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_static_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_static_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_static_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_dynamic_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_guided_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_static_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_guided_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_guided_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_static_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_guided_next)(gomp_ull *istart, gomp_ull *iend);

/* ordered.c */

void (*lib_GOMP_ordered_start)(void);
void (*lib_GOMP_ordered_end)(void);
void (*lib_GOMP_doacross_post)(long *counts);
void (*lib_GOMP_doacross_wait)(long first, ...);
void (*lib_GOMP_doacross_ull_post)(gomp_ull *counts);
void (*lib_GOMP_doacross_ull_wait)(gomp_ull first, ...);

/* parallel.c */

void (*lib_GOMP_parallel_start)(void (*fn)(void *), void *data, unsigned num_threads);
void (*lib_GOMP_parallel_end)(void);
void (*lib_GOMP_parallel)(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
bool (*lib_GOMP_cancellation_point)(int which);
bool (*lib_GOMP_cancel)(int which, bool do_cancel);

/* sections.c */

unsigned (*lib_GOMP_sections_start)(unsigned count);
unsigned (*lib_GOMP_sections_next)(void);
void (*lib_GOMP_parallel_sections_start)(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
void (*lib_GOMP_parallel_sections)(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
void (*lib_GOMP_sections_end)(void);
bool (*lib_GOMP_sections_end_cancel)(void);
void (*lib_GOMP_sections_end_nowait)(void);

/* single.c */

bool (*lib_GOMP_single_start)(void);
void (*lib_GOMP_single_copy_start)(void);
void (*lib_GOMP_single_copy_end)(void *data);

#ifdef __cplusplus
extern "C"
{
#endif

	void foo(void);

	/* barrier.c */

	void GOMP_barrier(void);
	bool GOMP_barrier_cancel(void);

	/* critical.c */

	void GOMP_critical_start(void);
	void GOMP_critical_end(void);
	void GOMP_critical_name_start(void **pptr);
	void GOMP_critical_name_end(void **pptr);

	/* loop.c */

	bool GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);
	bool GOMP_loop_runtime_next(long *istart, long *iend);
	bool GOMP_loop_ordered_runtime_next(long *istart, long *iend);
	void GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
	void GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
	void GOMP_loop_end(void);
	bool GOMP_loop_end_cancel(void);
	void GOMP_loop_end_nowait(void);
	bool GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_static_next(long *istart, long *iend);
	bool GOMP_loop_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_guided_next(long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);
	bool GOMP_loop_ordered_static_next(long *istart, long *iend);
	bool GOMP_loop_ordered_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_ordered_guided_next(long *istart, long *iend);

	/* loop_ull.c */

	bool GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);

	/* ordered.c */

	void GOMP_ordered_start(void);
	void GOMP_ordered_end(void);
	void GOMP_doacross_post(long *counts);
	void GOMP_doacross_wait(long first, ...);
	void GOMP_doacross_ull_post(gomp_ull *counts);
	void GOMP_doacross_ull_wait(gomp_ull first, ...);

	/* parallel.c */

	void GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);
	void GOMP_parallel_end(void);
	void GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
	bool GOMP_cancellation_point(int which);
	bool GOMP_cancel(int which, bool do_cancel);

	/* sections.c */

	unsigned GOMP_sections_start(unsigned count);
	unsigned GOMP_sections_next(void);
	void GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
	void GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
	void GOMP_sections_end(void);
	bool GOMP_sections_end_cancel(void);
	void GOMP_sections_end_nowait(void);

	/* single.c */

	bool GOMP_single_start(void);
	void GOMP_single_copy_start(void);
	void GOMP_single_copy_end(void *data);

#ifdef __cplusplus
}
#endif

#endif // hookomp_h__
