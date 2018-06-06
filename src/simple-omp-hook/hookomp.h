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

/* atomic.c */

void (*lib_GOMP_atomic_end)(void);
void (*lib_GOMP_atomic_start)(void);

/* barrier.c */

void (*lib_GOMP_barrier)(void);
bool (*lib_GOMP_barrier_cancel)(void);

/* critical.c */

void (*lib_GOMP_critical_end)(void);
void (*lib_GOMP_critical_name_end)(void **pptr);
void (*lib_GOMP_critical_name_start)(void **pptr);
void (*lib_GOMP_critical_start)(void);

/* loop.c */

bool (*lib_GOMP_loop_doacross_dynamic_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_guided_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_runtime_start)(unsigned ncounts, long *counts, long *istart, long *iend);
bool (*lib_GOMP_loop_doacross_static_start)(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
void (*lib_GOMP_loop_end)(void);
bool (*lib_GOMP_loop_end_cancel)(void);
void (*lib_GOMP_loop_end_nowait)(void);
bool (*lib_GOMP_loop_guided_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_guided_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_nonmonotonic_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_dynamic_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_dynamic_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_guided_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_guided_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_runtime_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_runtime_start)(long start, long end, long incr, long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_static_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_ordered_static_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
bool (*lib_GOMP_loop_runtime_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_runtime_start)(long start, long end, long incr, long *istart, long *iend);
bool (*lib_GOMP_loop_static_next)(long *istart, long *iend);
bool (*lib_GOMP_loop_static_start)(long start, long end, long incr, long chunk_size, long *istart, long *iend);
void (*lib_GOMP_parallel_loop_dynamic)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_dynamic_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
void (*lib_GOMP_parallel_loop_guided)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_guided_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
void (*lib_GOMP_parallel_loop_nonmonotonic_dynamic)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_nonmonotonic_guided)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_runtime)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
void (*lib_GOMP_parallel_loop_runtime_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
void (*lib_GOMP_parallel_loop_static)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
void (*lib_GOMP_parallel_loop_static_start)(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

/* loop_ull.c */

bool (*lib_GOMP_loop_ull_doacross_dynamic_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_guided_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_runtime_start)(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_doacross_static_start)(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_guided_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_guided_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_nonmonotonic_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_dynamic_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_dynamic_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_guided_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_guided_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_runtime_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_runtime_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_static_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_ordered_static_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_runtime_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_runtime_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_static_next)(gomp_ull *istart, gomp_ull *iend);
bool (*lib_GOMP_loop_ull_static_start)(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

/* ordered.c */

void (*lib_GOMP_doacross_post)(long *counts);
void (*lib_GOMP_doacross_ull_post)(gomp_ull *counts);
void (*lib_GOMP_doacross_ull_wait)(gomp_ull first, ...);
void (*lib_GOMP_doacross_wait)(long first, ...);
void (*lib_GOMP_ordered_end)(void);
void (*lib_GOMP_ordered_start)(void);

/* parallel.c */

bool (*lib_GOMP_cancel)(int which, bool do_cancel);
bool (*lib_GOMP_cancellation_point)(int which);
void (*lib_GOMP_parallel)(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
void (*lib_GOMP_parallel_end)(void);
void (*lib_GOMP_parallel_start)(void (*fn)(void *), void *data, unsigned num_threads);

/* sections.c */

void (*lib_GOMP_parallel_sections)(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
void (*lib_GOMP_parallel_sections_start)(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
void (*lib_GOMP_sections_end)(void);
bool (*lib_GOMP_sections_end_cancel)(void);
void (*lib_GOMP_sections_end_nowait)(void);
unsigned (*lib_GOMP_sections_next)(void);
unsigned (*lib_GOMP_sections_start)(unsigned count);

/* single.c */

void (*lib_GOMP_single_copy_end)(void *data);
void *(*lib_GOMP_single_copy_start)(void);
bool (*lib_GOMP_single_start)(void);

/* task.c */

void (*lib_GOMP_PLUGIN_target_task_completion)(void *data);
void (*lib_GOMP_task)(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);
void (*lib_GOMP_taskgroup_end)(void);
void (*lib_GOMP_taskgroup_start)(void);
void (*lib_GOMP_taskwait)(void);
void (*lib_GOMP_taskyield)(void);

/* target.c */

void (*lib_GOMP_offload_register)(const void *host_table, int target_type, const void *target_data);
void (*lib_GOMP_offload_register_ver)(unsigned version, const void *host_table, int target_type, const void *target_data);
void (*lib_GOMP_offload_unregister)(const void *host_table, int target_type, const void *target_data);
void (*lib_GOMP_offload_unregister_ver)(unsigned version, const void *host_table, int target_type, const void *target_data);
void (*lib_GOMP_target)(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
void (*lib_GOMP_target_data)(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
void (*lib_GOMP_target_data_ext)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
void (*lib_GOMP_target_end_data)(void);
void (*lib_GOMP_target_enter_exit_data)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
void (*lib_GOMP_target_ext)(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);
void (*lib_GOMP_target_update)(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
void (*lib_GOMP_target_update_ext)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
void (*lib_GOMP_teams)(unsigned int num_teams, unsigned int thread_limit);

/* taskloop.c */

void (*lib_GOMP_taskloop)(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step);

/* oacc-parallel.c */

void (*lib_GOACC_data_end)(void);
void (*lib_GOACC_data_start)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
void (*lib_GOACC_declare)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
void (*lib_GOACC_enter_exit_data)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
int (*lib_GOACC_get_num_threads)(void);
int (*lib_GOACC_get_thread_num)(void);
void (*lib_GOACC_parallel)(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...);
void (*lib_GOACC_parallel_keyed)(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...);
void (*lib_GOACC_update)(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
void (*lib_GOACC_wait)(int async, int num_waits, ...);

#ifdef __cplusplus
extern "C"
{
#endif

	void foo(void);
	/* atomic.c */

	void GOMP_atomic_end(void);
	void GOMP_atomic_start(void);

	/* barrier.c */

	void GOMP_barrier(void);
	bool GOMP_barrier_cancel(void);

	/* critical.c */

	void GOMP_critical_end(void);
	void GOMP_critical_name_end(void **pptr);
	void GOMP_critical_name_start(void **pptr);
	void GOMP_critical_start(void);

	/* loop.c */

	bool GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);
	bool GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	void GOMP_loop_end(void);
	bool GOMP_loop_end_cancel(void);
	void GOMP_loop_end_nowait(void);
	bool GOMP_loop_guided_next(long *istart, long *iend);
	bool GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);
	bool GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_dynamic_next(long *istart, long *iend);
	bool GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_guided_next(long *istart, long *iend);
	bool GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_ordered_runtime_next(long *istart, long *iend);
	bool GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool GOMP_loop_ordered_static_next(long *istart, long *iend);
	bool GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool GOMP_loop_runtime_next(long *istart, long *iend);
	bool GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool GOMP_loop_static_next(long *istart, long *iend);
	bool GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	void GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
	void GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
	void GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

	/* loop_ull.c */

	bool GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);
	bool GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	/* ordered.c */

	void GOMP_doacross_post(long *counts);
	void GOMP_doacross_ull_post(gomp_ull *counts);
	void GOMP_doacross_ull_wait(gomp_ull first, ...);
	void GOMP_doacross_wait(long first, ...);
	void GOMP_ordered_end(void);
	void GOMP_ordered_start(void);

	/* parallel.c */

	bool GOMP_cancel(int which, bool do_cancel);
	bool GOMP_cancellation_point(int which);
	void GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
	void GOMP_parallel_end(void);
	void GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);

	/* sections.c */

	void GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
	void GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
	void GOMP_sections_end(void);
	bool GOMP_sections_end_cancel(void);
	void GOMP_sections_end_nowait(void);
	unsigned GOMP_sections_next(void);
	unsigned GOMP_sections_start(unsigned count);

	/* single.c */

	void GOMP_single_copy_end(void *data);
	void *GOMP_single_copy_start(void);
	bool GOMP_single_start(void);

	/* task.c */

	void GOMP_PLUGIN_target_task_completion(void *data);
	void GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);
	void GOMP_taskgroup_end(void);
	void GOMP_taskgroup_start(void);
	void GOMP_taskwait(void);
	void GOMP_taskyield(void);

	/* target.c */

	void GOMP_offload_register(const void *host_table, int target_type, const void *target_data);
	void GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
	void GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data);
	void GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
	void GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
	void GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
	void GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
	void GOMP_target_end_data(void);
	void GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
	void GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);
	void GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
	void GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
	void GOMP_teams(unsigned int num_teams, unsigned int thread_limit);

	/* taskloop.c */

	void GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step);

	/* oacc-parallel.c */

	void GOACC_data_end(void);
	void GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
	void GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
	void GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
	int GOACC_get_num_threads(void);
	int GOACC_get_thread_num(void);
	void GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...);
	void GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...);
	void GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
	void GOACC_wait(int async, int num_waits, ...);

#ifdef __cplusplus
}
#endif

#endif // hookomp_h__
