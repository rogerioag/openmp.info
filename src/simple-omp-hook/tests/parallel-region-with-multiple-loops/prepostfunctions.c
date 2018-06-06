#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

typedef unsigned long long gomp_ull;
typedef long TYPE;

int num_GOMP_barrier = 0;
int num_GOMP_barrier_cancel = 0;
int num_GOMP_critical_start = 0;
int num_GOMP_critical_end = 0;
int num_GOMP_critical_name_start = 0;
int num_GOMP_critical_name_end = 0;
int num_GOMP_loop_ull_runtime_start = 0;
int num_GOMP_loop_ull_ordered_runtime_start = 0;
int num_GOMP_loop_ull_doacross_runtime_start = 0;
int num_GOMP_loop_ull_runtime_next = 0;
int num_GOMP_loop_ull_ordered_runtime_next = 0;
int num_GOMP_loop_ull_static_start = 0;
int num_GOMP_loop_ull_dynamic_start = 0;
int num_GOMP_loop_ull_guided_start = 0;
int num_GOMP_loop_ull_nonmonotonic_dynamic_start = 0;
int num_GOMP_loop_ull_nonmonotonic_guided_start = 0;
int num_GOMP_loop_ull_ordered_static_start = 0;
int num_GOMP_loop_ull_ordered_dynamic_start = 0;
int num_GOMP_loop_ull_ordered_guided_start = 0;
int num_GOMP_loop_ull_doacross_static_start = 0;
int num_GOMP_loop_ull_doacross_dynamic_start = 0;
int num_GOMP_loop_ull_doacross_guided_start = 0;
int num_GOMP_loop_ull_static_next = 0;
int num_GOMP_loop_ull_dynamic_next = 0;
int num_GOMP_loop_ull_guided_next = 0;
int num_GOMP_loop_ull_nonmonotonic_dynamic_next = 0;
int num_GOMP_loop_ull_nonmonotonic_guided_next = 0;
int num_GOMP_loop_ull_ordered_static_next = 0;
int num_GOMP_loop_ull_ordered_dynamic_next = 0;
int num_GOMP_loop_ull_ordered_guided_next = 0;
int num_GOMP_loop_runtime_start = 0;
int num_GOMP_loop_ordered_runtime_start = 0;
int num_GOMP_loop_doacross_runtime_start = 0;
int num_GOMP_loop_runtime_next = 0;
int num_GOMP_loop_ordered_runtime_next = 0;
int num_GOMP_parallel_loop_static_start = 0;
int num_GOMP_parallel_loop_dynamic_start = 0;
int num_GOMP_parallel_loop_guided_start = 0;
int num_GOMP_parallel_loop_runtime_start = 0;
int num_GOMP_parallel_loop_static = 0;
int num_GOMP_parallel_loop_dynamic = 0;
int num_GOMP_parallel_loop_guided = 0;
int num_GOMP_parallel_loop_nonmonotonic_dynamic = 0;
int num_GOMP_parallel_loop_nonmonotonic_guided = 0;
int num_GOMP_parallel_loop_runtime = 0;
int num_GOMP_loop_end = 0;
int num_GOMP_loop_end_cancel = 0;
int num_GOMP_loop_end_nowait = 0;
int num_GOMP_loop_static_start = 0;
int num_GOMP_loop_dynamic_start = 0;
int num_GOMP_loop_guided_start = 0;
int num_GOMP_loop_nonmonotonic_dynamic_start = 0;
int num_GOMP_loop_nonmonotonic_guided_start = 0;
int num_GOMP_loop_ordered_static_start = 0;
int num_GOMP_loop_ordered_dynamic_start = 0;
int num_GOMP_loop_ordered_guided_start = 0;
int num_GOMP_loop_doacross_static_start = 0;
int num_GOMP_loop_doacross_dynamic_start = 0;
int num_GOMP_loop_doacross_guided_start = 0;
int num_GOMP_loop_static_next = 0;
int num_GOMP_loop_dynamic_next = 0;
int num_GOMP_loop_guided_next = 0;
int num_GOMP_loop_nonmonotonic_dynamic_next = 0;
int num_GOMP_loop_nonmonotonic_guided_next = 0;
int num_GOMP_loop_ordered_static_next = 0;
int num_GOMP_loop_ordered_dynamic_next = 0;
int num_GOMP_loop_ordered_guided_next = 0;
int num_GOMP_ordered_start = 0;
int num_GOMP_ordered_end = 0;
int num_GOMP_doacross_post = 0;
int num_GOMP_doacross_wait = 0;
int num_GOMP_doacross_ull_post = 0;
int num_GOMP_doacross_ull_wait = 0;
int num_GOMP_parallel_start = 0;
int num_GOMP_parallel_end = 0;
int num_GOMP_parallel = 0;
int num_GOMP_cancellation_point = 0;
int num_GOMP_cancel = 0;
int num_GOMP_sections_start = 0;
int num_GOMP_sections_next = 0;
int num_GOMP_parallel_sections_start = 0;
int num_GOMP_parallel_sections = 0;
int num_GOMP_sections_end = 0;
int num_GOMP_sections_end_cancel = 0;
int num_GOMP_sections_end_nowait = 0;
int num_GOMP_single_start = 0;
int num_GOMP_single_copy_start = 0;
int num_GOMP_single_copy_end = 0;
int num_GOMP_offload_register_ver = 0;
int num_GOMP_offload_register = 0;
int num_GOMP_offload_unregister_ver = 0;
int num_GOMP_offload_unregister = 0;
int num_GOMP_target = 0;
int num_GOMP_target_ext = 0;
int num_GOMP_target_data = 0;
int num_GOMP_target_data_ext = 0;
int num_GOMP_target_end_data = 0;
int num_GOMP_target_update = 0;
int num_GOMP_target_update_ext = 0;
int num_GOMP_target_enter_exit_data = 0;
int num_GOMP_teams = 0;


void print_results()
{
	printf("Number of GOMP_barrier: %d\n", num_GOMP_barrier);
	printf("Number of GOMP_barrier_cancel: %d\n", num_GOMP_barrier_cancel);
	printf("Number of GOMP_critical_start: %d\n", num_GOMP_critical_start);
	printf("Number of GOMP_critical_end: %d\n", num_GOMP_critical_end);
	printf("Number of GOMP_critical_name_start: %d\n", num_GOMP_critical_name_start);
	printf("Number of GOMP_critical_name_end: %d\n", num_GOMP_critical_name_end);
	printf("Number of GOMP_atomic_start: %d\n", num_GOMP_atomic_start);
	printf("Number of GOMP_atomic_end: %d\n", num_GOMP_atomic_end);
	printf("Number of GOMP_loop_static_start: %d\n", num_GOMP_loop_static_start);
	printf("Number of GOMP_loop_dynamic_start: %d\n", num_GOMP_loop_dynamic_start);
	printf("Number of GOMP_loop_guided_start: %d\n", num_GOMP_loop_guided_start);
	printf("Number of GOMP_loop_runtime_start: %d\n", num_GOMP_loop_runtime_start);
	printf("Number of GOMP_loop_nonmonotonic_dynamic_start: %d\n", num_GOMP_loop_nonmonotonic_dynamic_start);
	printf("Number of GOMP_loop_nonmonotonic_guided_start: %d\n", num_GOMP_loop_nonmonotonic_guided_start);
	printf("Number of GOMP_loop_ordered_static_start: %d\n", num_GOMP_loop_ordered_static_start);
	printf("Number of GOMP_loop_ordered_dynamic_start: %d\n", num_GOMP_loop_ordered_dynamic_start);
	printf("Number of GOMP_loop_ordered_guided_start: %d\n", num_GOMP_loop_ordered_guided_start);
	printf("Number of GOMP_loop_ordered_runtime_start: %d\n", num_GOMP_loop_ordered_runtime_start);
	printf("Number of GOMP_loop_static_next: %d\n", num_GOMP_loop_static_next);
	printf("Number of GOMP_loop_dynamic_next: %d\n", num_GOMP_loop_dynamic_next);
	printf("Number of GOMP_loop_guided_next: %d\n", num_GOMP_loop_guided_next);
	printf("Number of GOMP_loop_runtime_next: %d\n", num_GOMP_loop_runtime_next);
	printf("Number of GOMP_loop_nonmonotonic_dynamic_next: %d\n", num_GOMP_loop_nonmonotonic_dynamic_next);
	printf("Number of GOMP_loop_nonmonotonic_guided_next: %d\n", num_GOMP_loop_nonmonotonic_guided_next);
	printf("Number of GOMP_loop_ordered_static_next: %d\n", num_GOMP_loop_ordered_static_next);
	printf("Number of GOMP_loop_ordered_dynamic_next: %d\n", num_GOMP_loop_ordered_dynamic_next);
	printf("Number of GOMP_loop_ordered_guided_next: %d\n", num_GOMP_loop_ordered_guided_next);
	printf("Number of GOMP_loop_ordered_runtime_next: %d\n", num_GOMP_loop_ordered_runtime_next);
	printf("Number of GOMP_loop_doacross_static_start: %d\n", num_GOMP_loop_doacross_static_start);
	printf("Number of GOMP_loop_doacross_dynamic_start: %d\n", num_GOMP_loop_doacross_dynamic_start);
	printf("Number of GOMP_loop_doacross_guided_start: %d\n", num_GOMP_loop_doacross_guided_start);
	printf("Number of GOMP_loop_doacross_runtime_start: %d\n", num_GOMP_loop_doacross_runtime_start);
	printf("Number of GOMP_parallel_loop_static_start: %d\n", num_GOMP_parallel_loop_static_start);
	printf("Number of GOMP_parallel_loop_dynamic_start: %d\n", num_GOMP_parallel_loop_dynamic_start);
	printf("Number of GOMP_parallel_loop_guided_start: %d\n", num_GOMP_parallel_loop_guided_start);
	printf("Number of GOMP_parallel_loop_runtime_start: %d\n", num_GOMP_parallel_loop_runtime_start);
	printf("Number of GOMP_parallel_loop_static: %d\n", num_GOMP_parallel_loop_static);
	printf("Number of GOMP_parallel_loop_dynamic: %d\n", num_GOMP_parallel_loop_dynamic);
	printf("Number of GOMP_parallel_loop_guided: %d\n", num_GOMP_parallel_loop_guided);
	printf("Number of GOMP_parallel_loop_runtime: %d\n", num_GOMP_parallel_loop_runtime);
	printf("Number of GOMP_parallel_loop_nonmonotonic_dynamic: %d\n", num_GOMP_parallel_loop_nonmonotonic_dynamic);
	printf("Number of GOMP_parallel_loop_nonmonotonic_guided: %d\n", num_GOMP_parallel_loop_nonmonotonic_guided);
	printf("Number of GOMP_loop_end: %d\n", num_GOMP_loop_end);
	printf("Number of GOMP_loop_end_nowait: %d\n", num_GOMP_loop_end_nowait);
	printf("Number of GOMP_loop_end_cancel: %d\n", num_GOMP_loop_end_cancel);
	printf("Number of GOMP_loop_ull_static_start: %d\n", num_GOMP_loop_ull_static_start);
	printf("Number of GOMP_loop_ull_dynamic_start: %d\n", num_GOMP_loop_ull_dynamic_start);
	printf("Number of GOMP_loop_ull_guided_start: %d\n", num_GOMP_loop_ull_guided_start);
	printf("Number of GOMP_loop_ull_runtime_start: %d\n", num_GOMP_loop_ull_runtime_start);
	printf("Number of GOMP_loop_ull_nonmonotonic_dynamic_start: %d\n", num_GOMP_loop_ull_nonmonotonic_dynamic_start);
	printf("Number of GOMP_loop_ull_nonmonotonic_guided_start: %d\n", num_GOMP_loop_ull_nonmonotonic_guided_start);
	printf("Number of GOMP_loop_ull_ordered_static_start: %d\n", num_GOMP_loop_ull_ordered_static_start);
	printf("Number of GOMP_loop_ull_ordered_dynamic_start: %d\n", num_GOMP_loop_ull_ordered_dynamic_start);
	printf("Number of GOMP_loop_ull_ordered_guided_start: %d\n", num_GOMP_loop_ull_ordered_guided_start);
	printf("Number of GOMP_loop_ull_ordered_runtime_start: %d\n", num_GOMP_loop_ull_ordered_runtime_start);
	printf("Number of GOMP_loop_ull_static_next: %d\n", num_GOMP_loop_ull_static_next);
	printf("Number of GOMP_loop_ull_dynamic_next: %d\n", num_GOMP_loop_ull_dynamic_next);
	printf("Number of GOMP_loop_ull_guided_next: %d\n", num_GOMP_loop_ull_guided_next);
	printf("Number of GOMP_loop_ull_runtime_next: %d\n", num_GOMP_loop_ull_runtime_next);
	printf("Number of GOMP_loop_ull_nonmonotonic_dynamic_next: %d\n", num_GOMP_loop_ull_nonmonotonic_dynamic_next);
	printf("Number of GOMP_loop_ull_nonmonotonic_guided_next: %d\n", num_GOMP_loop_ull_nonmonotonic_guided_next);
	printf("Number of GOMP_loop_ull_ordered_static_next: %d\n", num_GOMP_loop_ull_ordered_static_next);
	printf("Number of GOMP_loop_ull_ordered_dynamic_next: %d\n", num_GOMP_loop_ull_ordered_dynamic_next);
	printf("Number of GOMP_loop_ull_ordered_guided_next: %d\n", num_GOMP_loop_ull_ordered_guided_next);
	printf("Number of GOMP_loop_ull_ordered_runtime_next: %d\n", num_GOMP_loop_ull_ordered_runtime_next);
	printf("Number of GOMP_loop_ull_doacross_static_start: %d\n", num_GOMP_loop_ull_doacross_static_start);
	printf("Number of GOMP_loop_ull_doacross_dynamic_start: %d\n", num_GOMP_loop_ull_doacross_dynamic_start);
	printf("Number of GOMP_loop_ull_doacross_guided_start: %d\n", num_GOMP_loop_ull_doacross_guided_start);
	printf("Number of GOMP_loop_ull_doacross_runtime_start: %d\n", num_GOMP_loop_ull_doacross_runtime_start);
	printf("Number of GOMP_ordered_start: %d\n", num_GOMP_ordered_start);
	printf("Number of GOMP_ordered_end: %d\n", num_GOMP_ordered_end);
	printf("Number of GOMP_doacross_post: %d\n", num_GOMP_doacross_post);
	printf("Number of GOMP_doacross_wait: %d\n", num_GOMP_doacross_wait);
	printf("Number of GOMP_doacross_ull_post: %d\n", num_GOMP_doacross_ull_post);
	printf("Number of GOMP_doacross_ull_wait: %d\n", num_GOMP_doacross_ull_wait);
	printf("Number of GOMP_parallel_start: %d\n", num_GOMP_parallel_start);
	printf("Number of GOMP_parallel_end: %d\n", num_GOMP_parallel_end);
	printf("Number of GOMP_parallel: %d\n", num_GOMP_parallel);
	printf("Number of GOMP_cancel: %d\n", num_GOMP_cancel);
	printf("Number of GOMP_cancellation_point: %d\n", num_GOMP_cancellation_point);
	printf("Number of GOMP_task: %d\n", num_GOMP_task);
	printf("Number of GOMP_taskloop: %d\n", num_GOMP_taskloop);
	printf("Number of GOMP_taskloop_ull: %d\n", num_GOMP_taskloop_ull);
	printf("Number of GOMP_taskwait: %d\n", num_GOMP_taskwait);
	printf("Number of GOMP_taskyield: %d\n", num_GOMP_taskyield);
	printf("Number of GOMP_taskgroup_start: %d\n", num_GOMP_taskgroup_start);
	printf("Number of GOMP_taskgroup_end: %d\n", num_GOMP_taskgroup_end);
	printf("Number of GOMP_sections_start: %d\n", num_GOMP_sections_start);
	printf("Number of GOMP_sections_next: %d\n", num_GOMP_sections_next);
	printf("Number of GOMP_parallel_sections_start: %d\n", num_GOMP_parallel_sections_start);
	printf("Number of GOMP_parallel_sections: %d\n", num_GOMP_parallel_sections);
	printf("Number of GOMP_sections_end: %d\n", num_GOMP_sections_end);
	printf("Number of GOMP_sections_end_nowait: %d\n", num_GOMP_sections_end_nowait);
	printf("Number of GOMP_sections_end_cancel: %d\n", num_GOMP_sections_end_cancel);
	printf("Number of GOMP_single_start: %d\n", num_GOMP_single_start);
	printf("Number of GOMP_single_copy_start: %d\n", num_GOMP_single_copy_start);
	printf("Number of GOMP_single_copy_end: %d\n", num_GOMP_single_copy_end);
	printf("Number of GOMP_target: %d\n", num_GOMP_target);
	printf("Number of GOMP_target_ext: %d\n", num_GOMP_target_ext);
	printf("Number of GOMP_target_data: %d\n", num_GOMP_target_data);
	printf("Number of GOMP_target_data_ext: %d\n", num_GOMP_target_data_ext);
	printf("Number of GOMP_target_end_data: %d\n", num_GOMP_target_end_data);
	printf("Number of GOMP_target_update: %d\n", num_GOMP_target_update);
	printf("Number of GOMP_target_update_ext: %d\n", num_GOMP_target_update_ext);
	printf("Number of GOMP_target_enter_exit_data: %d\n", num_GOMP_target_enter_exit_data);
	printf("Number of GOMP_teams: %d\n", num_GOMP_teams);
}

void PRE_GOMP_barrier(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_barrier++;
}

void POST_GOMP_barrier(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_barrier_cancel++;
}

bool POST_GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_start(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_critical_start++;
}

void POST_GOMP_critical_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_end(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_critical_end++;
}

void POST_GOMP_critical_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
	num_GOMP_critical_name_start++;
}

void POST_GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
	num_GOMP_critical_name_end++;
}

void POST_GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_runtime_start++;
}

bool POST_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_runtime_start++;
}

bool POST_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_doacross_runtime_start++;
}

bool POST_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_runtime_next++;
}

bool POST_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_runtime_next++;
}

bool POST_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_static_start++;
}

bool POST_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_dynamic_start++;
}

bool POST_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_guided_start++;
}

bool POST_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_nonmonotonic_dynamic_start++;
}

bool POST_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_nonmonotonic_guided_start++;
}

bool POST_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_static_start++;
}

bool POST_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_dynamic_start++;
}

bool POST_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_guided_start++;
}

bool POST_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_doacross_static_start++;
}

bool POST_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_doacross_dynamic_start++;
}

bool POST_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_doacross_guided_start++;
}

bool POST_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_static_next++;
}

bool POST_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_dynamic_next++;
}

bool POST_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_guided_next++;
}

bool POST_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_nonmonotonic_dynamic_next++;
}

bool POST_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_nonmonotonic_guided_next++;
}

bool POST_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_static_next++;
}

bool POST_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_dynamic_next++;
}

bool POST_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ull_ordered_guided_next++;
}

bool POST_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_runtime_start++;
}

bool POST_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_runtime_start++;
}

bool POST_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_doacross_runtime_start++;
}

bool POST_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_runtime_next++;
}

bool POST_GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_runtime_next++;
}

bool POST_GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_static_start++;
}

void POST_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_dynamic_start++;
}

void POST_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_guided_start++;
}

void POST_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_runtime_start++;
}

void POST_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_static++;
}

void POST_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_dynamic++;
}

void POST_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_guided++;
}

void POST_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_nonmonotonic_dynamic++;
}

void POST_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_nonmonotonic_guided++;
}

void POST_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_loop_runtime++;
}

void POST_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_end++;
}

void POST_GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_end_cancel++;
}

bool POST_GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_end_nowait++;
}

void POST_GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_static_start++;
}

bool POST_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_dynamic_start++;
}

bool POST_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_guided_start++;
}

bool POST_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_nonmonotonic_dynamic_start++;
}

bool POST_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_nonmonotonic_guided_start++;
}

bool POST_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_static_start++;
}

bool POST_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_dynamic_start++;
}

bool POST_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_guided_start++;
}

bool POST_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_doacross_static_start++;
}

bool POST_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_doacross_dynamic_start++;
}

bool POST_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_doacross_guided_start++;
}

bool POST_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_static_next++;
}

bool POST_GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_dynamic_next++;
}

bool POST_GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_guided_next++;
}

bool POST_GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_nonmonotonic_dynamic_next++;
}

bool POST_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_nonmonotonic_guided_next++;
}

bool POST_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_static_next++;
}

bool POST_GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_dynamic_next++;
}

bool POST_GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	num_GOMP_loop_ordered_guided_next++;
}

bool POST_GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_ordered_start(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_ordered_start++;
}

void POST_GOMP_ordered_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_ordered_end++;
}

void POST_GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
	num_GOMP_doacross_post++;
}

void POST_GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
	num_GOMP_doacross_wait++;
}

void POST_GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
	num_GOMP_doacross_ull_post++;
}

void POST_GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
	num_GOMP_doacross_ull_wait++;
}

void POST_GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_start++;
}

void POST_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_end++;
}

void POST_GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel++;
}

void POST_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
	num_GOMP_cancellation_point++;
}

bool POST_GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
	num_GOMP_cancel++;
}

bool POST_GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
}

unsigned PRE_GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
	num_GOMP_sections_start++;
}

unsigned POST_GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
}

unsigned PRE_GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_sections_next++;
}

unsigned POST_GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_sections_start++;
}

void POST_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags)
{
	PRINT_FUNC_NAME;
	num_GOMP_parallel_sections++;
}

void POST_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_sections_end++;
}

void POST_GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_sections_end_cancel++;
}

bool POST_GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_sections_end_nowait++;
}

void POST_GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_single_start++;
}

bool POST_GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_single_copy_start++;
}

void POST_GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_single_copy_end(void *data)
{
	PRINT_FUNC_NAME;
	num_GOMP_single_copy_end++;
}

void POST_GOMP_single_copy_end(void *data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	num_GOMP_offload_register_ver++;
}

void POST_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	num_GOMP_offload_register++;
}

void POST_GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	num_GOMP_offload_unregister_ver++;
}

void POST_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	num_GOMP_offload_unregister++;
}

void POST_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target(int device, void (*fn)(void *), const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	num_GOMP_target++;
}

void POST_GOMP_target(int device, void (*fn)(void *), const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_ext(int device, void (*fn)(void *), unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_ext++;
}

void POST_GOMP_target_ext(int device, void (*fn)(void *), unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_data(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_data++;
}

void POST_GOMP_target_data(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_data_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_data_ext++;
}

void POST_GOMP_target_data_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_end_data(void)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_end_data++;
}

void POST_GOMP_target_end_data(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_update(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_update++;
}

void POST_GOMP_target_update(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_update_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_update_ext++;
}

void POST_GOMP_target_update_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_enter_exit_data(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	num_GOMP_target_enter_exit_data++;
}

void POST_GOMP_target_enter_exit_data(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_teams(unsigned int num_teams, unsigned int thread_limit)
{
	PRINT_FUNC_NAME;
	num_GOMP_teams++;
}

void POST_GOMP_teams(unsigned int num_teams, unsigned int thread_limit)
{
	PRINT_FUNC_NAME;
}
