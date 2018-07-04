#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
typedef unsigned long long gomp_ull;
typedef _Bool bool;
typedef long TYPE;
#define NUM_FUNCTIONS 120
// Keep the partial counters.
unsigned long int partial_count[NUM_FUNCTIONS];
unsigned long int accum_count[NUM_FUNCTIONS];
enum omp_idx_function
{
	idx_GOMP_atomic_end,
	idx_GOMP_atomic_start,
	idx_GOMP_barrier,
	idx_GOMP_barrier_cancel,
	idx_GOMP_critical_end,
	idx_GOMP_critical_name_end,
	idx_GOMP_critical_name_start,
	idx_GOMP_critical_start,
	idx_GOMP_loop_doacross_dynamic_start,
	idx_GOMP_loop_doacross_guided_start,
	idx_GOMP_loop_doacross_runtime_start,
	idx_GOMP_loop_doacross_static_start,
	idx_GOMP_loop_dynamic_next,
	idx_GOMP_loop_dynamic_start,
	idx_GOMP_loop_end,
	idx_GOMP_loop_end_cancel,
	idx_GOMP_loop_end_nowait,
	idx_GOMP_loop_guided_next,
	idx_GOMP_loop_guided_start,
	idx_GOMP_loop_nonmonotonic_dynamic_next,
	idx_GOMP_loop_nonmonotonic_dynamic_start,
	idx_GOMP_loop_nonmonotonic_guided_next,
	idx_GOMP_loop_nonmonotonic_guided_start,
	idx_GOMP_loop_ordered_dynamic_next,
	idx_GOMP_loop_ordered_dynamic_start,
	idx_GOMP_loop_ordered_guided_next,
	idx_GOMP_loop_ordered_guided_start,
	idx_GOMP_loop_ordered_runtime_next,
	idx_GOMP_loop_ordered_runtime_start,
	idx_GOMP_loop_ordered_static_next,
	idx_GOMP_loop_ordered_static_start,
	idx_GOMP_loop_runtime_next,
	idx_GOMP_loop_runtime_start,
	idx_GOMP_loop_static_next,
	idx_GOMP_loop_static_start,
	idx_GOMP_parallel_loop_dynamic,
	idx_GOMP_parallel_loop_dynamic_start,
	idx_GOMP_parallel_loop_guided,
	idx_GOMP_parallel_loop_guided_start,
	idx_GOMP_parallel_loop_nonmonotonic_dynamic,
	idx_GOMP_parallel_loop_nonmonotonic_guided,
	idx_GOMP_parallel_loop_runtime,
	idx_GOMP_parallel_loop_runtime_start,
	idx_GOMP_parallel_loop_static,
	idx_GOMP_parallel_loop_static_start,
	idx_GOMP_loop_ull_doacross_dynamic_start,
	idx_GOMP_loop_ull_doacross_guided_start,
	idx_GOMP_loop_ull_doacross_runtime_start,
	idx_GOMP_loop_ull_doacross_static_start,
	idx_GOMP_loop_ull_dynamic_next,
	idx_GOMP_loop_ull_dynamic_start,
	idx_GOMP_loop_ull_guided_next,
	idx_GOMP_loop_ull_guided_start,
	idx_GOMP_loop_ull_nonmonotonic_dynamic_next,
	idx_GOMP_loop_ull_nonmonotonic_dynamic_start,
	idx_GOMP_loop_ull_nonmonotonic_guided_next,
	idx_GOMP_loop_ull_nonmonotonic_guided_start,
	idx_GOMP_loop_ull_ordered_dynamic_next,
	idx_GOMP_loop_ull_ordered_dynamic_start,
	idx_GOMP_loop_ull_ordered_guided_next,
	idx_GOMP_loop_ull_ordered_guided_start,
	idx_GOMP_loop_ull_ordered_runtime_next,
	idx_GOMP_loop_ull_ordered_runtime_start,
	idx_GOMP_loop_ull_ordered_static_next,
	idx_GOMP_loop_ull_ordered_static_start,
	idx_GOMP_loop_ull_runtime_next,
	idx_GOMP_loop_ull_runtime_start,
	idx_GOMP_loop_ull_static_next,
	idx_GOMP_loop_ull_static_start,
	idx_GOMP_doacross_post,
	idx_GOMP_doacross_ull_post,
	idx_GOMP_doacross_ull_wait,
	idx_GOMP_doacross_wait,
	idx_GOMP_ordered_end,
	idx_GOMP_ordered_start,
	idx_GOMP_cancel,
	idx_GOMP_cancellation_point,
	idx_GOMP_parallel,
	idx_GOMP_parallel_end,
	idx_GOMP_parallel_start,
	idx_GOMP_parallel_sections,
	idx_GOMP_parallel_sections_start,
	idx_GOMP_sections_end,
	idx_GOMP_sections_end_cancel,
	idx_GOMP_sections_end_nowait,
	idx_GOMP_sections_next,
	idx_GOMP_sections_start,
	idx_GOMP_single_copy_end,
	idx_GOMP_single_copy_start,
	idx_GOMP_single_start,
	idx_GOMP_PLUGIN_target_task_completion,
	idx_GOMP_task,
	idx_GOMP_taskgroup_end,
	idx_GOMP_taskgroup_start,
	idx_GOMP_taskwait,
	idx_GOMP_taskyield,
	idx_GOMP_offload_register,
	idx_GOMP_offload_register_ver,
	idx_GOMP_offload_unregister,
	idx_GOMP_offload_unregister_ver,
	idx_GOMP_target,
	idx_GOMP_target_data,
	idx_GOMP_target_data_ext,
	idx_GOMP_target_end_data,
	idx_GOMP_target_enter_exit_data,
	idx_GOMP_target_ext,
	idx_GOMP_target_update,
	idx_GOMP_target_update_ext,
	idx_GOMP_teams,
	idx_GOMP_taskloop,
	idx_GOACC_data_end,
	idx_GOACC_data_start,
	idx_GOACC_declare,
	idx_GOACC_enter_exit_data,
	idx_GOACC_get_num_threads,
	idx_GOACC_get_thread_num,
	idx_GOACC_parallel,
	idx_GOACC_parallel_keyed,
	idx_GOACC_update,
	idx_GOACC_wait
} omp_idx_function;

#define BUFFER_SIZE 10240

void print_results_csv_partial(void)
{
	char buffer[BUFFER_SIZE];

	snprintf(buffer, sizeof(buffer), "Number of GOMP_atomic_end, Number of GOMP_atomic_start, Number of GOMP_barrier, Number of GOMP_barrier_cancel, Number of GOMP_critical_end, Number of GOMP_critical_name_end, Number of GOMP_critical_name_start, Number of GOMP_critical_start, Number of GOMP_loop_doacross_dynamic_start, Number of GOMP_loop_doacross_guided_start, Number of GOMP_loop_doacross_runtime_start, Number of GOMP_loop_doacross_static_start, Number of GOMP_loop_dynamic_next, Number of GOMP_loop_dynamic_start, Number of GOMP_loop_end, Number of GOMP_loop_end_cancel, Number of GOMP_loop_end_nowait, Number of GOMP_loop_guided_next, Number of GOMP_loop_guided_start, Number of GOMP_loop_nonmonotonic_dynamic_next, Number of GOMP_loop_nonmonotonic_dynamic_start, Number of GOMP_loop_nonmonotonic_guided_next, Number of GOMP_loop_nonmonotonic_guided_start, Number of GOMP_loop_ordered_dynamic_next, Number of GOMP_loop_ordered_dynamic_start, Number of GOMP_loop_ordered_guided_next, Number of GOMP_loop_ordered_guided_start, Number of GOMP_loop_ordered_runtime_next, Number of GOMP_loop_ordered_runtime_start, Number of GOMP_loop_ordered_static_next, Number of GOMP_loop_ordered_static_start, Number of GOMP_loop_runtime_next, Number of GOMP_loop_runtime_start, Number of GOMP_loop_static_next, Number of GOMP_loop_static_start, Number of GOMP_parallel_loop_dynamic, Number of GOMP_parallel_loop_dynamic_start, Number of GOMP_parallel_loop_guided, Number of GOMP_parallel_loop_guided_start, Number of GOMP_parallel_loop_nonmonotonic_dynamic, Number of GOMP_parallel_loop_nonmonotonic_guided, Number of GOMP_parallel_loop_runtime, Number of GOMP_parallel_loop_runtime_start, Number of GOMP_parallel_loop_static, Number of GOMP_parallel_loop_static_start, Number of GOMP_loop_ull_doacross_dynamic_start, Number of GOMP_loop_ull_doacross_guided_start, Number of GOMP_loop_ull_doacross_runtime_start, Number of GOMP_loop_ull_doacross_static_start, Number of GOMP_loop_ull_dynamic_next, Number of GOMP_loop_ull_dynamic_start, Number of GOMP_loop_ull_guided_next, Number of GOMP_loop_ull_guided_start, Number of GOMP_loop_ull_nonmonotonic_dynamic_next, Number of GOMP_loop_ull_nonmonotonic_dynamic_start, Number of GOMP_loop_ull_nonmonotonic_guided_next, Number of GOMP_loop_ull_nonmonotonic_guided_start, Number of GOMP_loop_ull_ordered_dynamic_next, Number of GOMP_loop_ull_ordered_dynamic_start, Number of GOMP_loop_ull_ordered_guided_next, Number of GOMP_loop_ull_ordered_guided_start, Number of GOMP_loop_ull_ordered_runtime_next, Number of GOMP_loop_ull_ordered_runtime_start, Number of GOMP_loop_ull_ordered_static_next, Number of GOMP_loop_ull_ordered_static_start, Number of GOMP_loop_ull_runtime_next, Number of GOMP_loop_ull_runtime_start, Number of GOMP_loop_ull_static_next, Number of GOMP_loop_ull_static_start, Number of GOMP_doacross_post, Number of GOMP_doacross_ull_post, Number of GOMP_doacross_ull_wait, Number of GOMP_doacross_wait, Number of GOMP_ordered_end, Number of GOMP_ordered_start, Number of GOMP_cancel, Number of GOMP_cancellation_point, Number of GOMP_parallel, Number of GOMP_parallel_end, Number of GOMP_parallel_start, Number of GOMP_parallel_sections, Number of GOMP_parallel_sections_start, Number of GOMP_sections_end, Number of GOMP_sections_end_cancel, Number of GOMP_sections_end_nowait, Number of GOMP_sections_next, Number of GOMP_sections_start, Number of GOMP_single_copy_end, Number of GOMP_single_copy_start, Number of GOMP_single_start, Number of GOMP_PLUGIN_target_task_completion, Number of GOMP_task, Number of GOMP_taskgroup_end, Number of GOMP_taskgroup_start, Number of GOMP_taskwait, Number of GOMP_taskyield, Number of GOMP_offload_register, Number of GOMP_offload_register_ver, Number of GOMP_offload_unregister, Number of GOMP_offload_unregister_ver, Number of GOMP_target, Number of GOMP_target_data, Number of GOMP_target_data_ext, Number of GOMP_target_end_data, Number of GOMP_target_enter_exit_data, Number of GOMP_target_ext, Number of GOMP_target_update, Number of GOMP_target_update_ext, Number of GOMP_teams, Number of GOMP_taskloop, Number of GOACC_data_end, Number of GOACC_data_start, Number of GOACC_declare, Number of GOACC_enter_exit_data, Number of GOACC_get_num_threads, Number of GOACC_get_thread_num, Number of GOACC_parallel, Number of GOACC_parallel_keyed, Number of GOACC_update, Number of GOACC_wait\n");
	snprintf(buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer), "%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu", partial_count[idx_GOMP_atomic_end], partial_count[idx_GOMP_atomic_start], partial_count[idx_GOMP_barrier], partial_count[idx_GOMP_barrier_cancel], partial_count[idx_GOMP_critical_end], partial_count[idx_GOMP_critical_name_end], partial_count[idx_GOMP_critical_name_start], partial_count[idx_GOMP_critical_start], partial_count[idx_GOMP_loop_doacross_dynamic_start], partial_count[idx_GOMP_loop_doacross_guided_start], partial_count[idx_GOMP_loop_doacross_runtime_start], partial_count[idx_GOMP_loop_doacross_static_start], partial_count[idx_GOMP_loop_dynamic_next], partial_count[idx_GOMP_loop_dynamic_start], partial_count[idx_GOMP_loop_end], partial_count[idx_GOMP_loop_end_cancel], partial_count[idx_GOMP_loop_end_nowait], partial_count[idx_GOMP_loop_guided_next], partial_count[idx_GOMP_loop_guided_start], partial_count[idx_GOMP_loop_nonmonotonic_dynamic_next], partial_count[idx_GOMP_loop_nonmonotonic_dynamic_start], partial_count[idx_GOMP_loop_nonmonotonic_guided_next], partial_count[idx_GOMP_loop_nonmonotonic_guided_start], partial_count[idx_GOMP_loop_ordered_dynamic_next], partial_count[idx_GOMP_loop_ordered_dynamic_start], partial_count[idx_GOMP_loop_ordered_guided_next], partial_count[idx_GOMP_loop_ordered_guided_start], partial_count[idx_GOMP_loop_ordered_runtime_next], partial_count[idx_GOMP_loop_ordered_runtime_start], partial_count[idx_GOMP_loop_ordered_static_next], partial_count[idx_GOMP_loop_ordered_static_start], partial_count[idx_GOMP_loop_runtime_next], partial_count[idx_GOMP_loop_runtime_start], partial_count[idx_GOMP_loop_static_next], partial_count[idx_GOMP_loop_static_start], partial_count[idx_GOMP_parallel_loop_dynamic], partial_count[idx_GOMP_parallel_loop_dynamic_start], partial_count[idx_GOMP_parallel_loop_guided], partial_count[idx_GOMP_parallel_loop_guided_start], partial_count[idx_GOMP_parallel_loop_nonmonotonic_dynamic], partial_count[idx_GOMP_parallel_loop_nonmonotonic_guided], partial_count[idx_GOMP_parallel_loop_runtime], partial_count[idx_GOMP_parallel_loop_runtime_start], partial_count[idx_GOMP_parallel_loop_static], partial_count[idx_GOMP_parallel_loop_static_start], partial_count[idx_GOMP_loop_ull_doacross_dynamic_start], partial_count[idx_GOMP_loop_ull_doacross_guided_start], partial_count[idx_GOMP_loop_ull_doacross_runtime_start], partial_count[idx_GOMP_loop_ull_doacross_static_start], partial_count[idx_GOMP_loop_ull_dynamic_next], partial_count[idx_GOMP_loop_ull_dynamic_start], partial_count[idx_GOMP_loop_ull_guided_next], partial_count[idx_GOMP_loop_ull_guided_start], partial_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_next], partial_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_start], partial_count[idx_GOMP_loop_ull_nonmonotonic_guided_next], partial_count[idx_GOMP_loop_ull_nonmonotonic_guided_start], partial_count[idx_GOMP_loop_ull_ordered_dynamic_next], partial_count[idx_GOMP_loop_ull_ordered_dynamic_start], partial_count[idx_GOMP_loop_ull_ordered_guided_next], partial_count[idx_GOMP_loop_ull_ordered_guided_start], partial_count[idx_GOMP_loop_ull_ordered_runtime_next], partial_count[idx_GOMP_loop_ull_ordered_runtime_start], partial_count[idx_GOMP_loop_ull_ordered_static_next], partial_count[idx_GOMP_loop_ull_ordered_static_start], partial_count[idx_GOMP_loop_ull_runtime_next], partial_count[idx_GOMP_loop_ull_runtime_start], partial_count[idx_GOMP_loop_ull_static_next], partial_count[idx_GOMP_loop_ull_static_start], partial_count[idx_GOMP_doacross_post], partial_count[idx_GOMP_doacross_ull_post], partial_count[idx_GOMP_doacross_ull_wait], partial_count[idx_GOMP_doacross_wait], partial_count[idx_GOMP_ordered_end], partial_count[idx_GOMP_ordered_start], partial_count[idx_GOMP_cancel], partial_count[idx_GOMP_cancellation_point], partial_count[idx_GOMP_parallel], partial_count[idx_GOMP_parallel_end], partial_count[idx_GOMP_parallel_start], partial_count[idx_GOMP_parallel_sections], partial_count[idx_GOMP_parallel_sections_start], partial_count[idx_GOMP_sections_end], partial_count[idx_GOMP_sections_end_cancel], partial_count[idx_GOMP_sections_end_nowait], partial_count[idx_GOMP_sections_next], partial_count[idx_GOMP_sections_start], partial_count[idx_GOMP_single_copy_end], partial_count[idx_GOMP_single_copy_start], partial_count[idx_GOMP_single_start], partial_count[idx_GOMP_PLUGIN_target_task_completion], partial_count[idx_GOMP_task], partial_count[idx_GOMP_taskgroup_end], partial_count[idx_GOMP_taskgroup_start], partial_count[idx_GOMP_taskwait], partial_count[idx_GOMP_taskyield], partial_count[idx_GOMP_offload_register], partial_count[idx_GOMP_offload_register_ver], partial_count[idx_GOMP_offload_unregister], partial_count[idx_GOMP_offload_unregister_ver], partial_count[idx_GOMP_target], partial_count[idx_GOMP_target_data], partial_count[idx_GOMP_target_data_ext], partial_count[idx_GOMP_target_end_data], partial_count[idx_GOMP_target_enter_exit_data], partial_count[idx_GOMP_target_ext], partial_count[idx_GOMP_target_update], partial_count[idx_GOMP_target_update_ext], partial_count[idx_GOMP_teams], partial_count[idx_GOMP_taskloop], partial_count[idx_GOACC_data_end], partial_count[idx_GOACC_data_start], partial_count[idx_GOACC_declare], partial_count[idx_GOACC_enter_exit_data], partial_count[idx_GOACC_get_num_threads], partial_count[idx_GOACC_get_thread_num], partial_count[idx_GOACC_parallel], partial_count[idx_GOACC_parallel_keyed], partial_count[idx_GOACC_update], partial_count[idx_GOACC_wait]);

	char filename[512];
	snprintf(filename, sizeof(filename), "partial_results_%d.csv", accum_count[idx_GOMP_parallel_end]);

	FILE *fout = fopen(filename, "w");
	fprintf(fout, buffer);
	fclose(fout);
}

void print_results_csv_accum(void)
{
	char buffer[BUFFER_SIZE];

	snprintf(buffer, sizeof(buffer), "Number of GOMP_atomic_end, Number of GOMP_atomic_start, Number of GOMP_barrier, Number of GOMP_barrier_cancel, Number of GOMP_critical_end, Number of GOMP_critical_name_end, Number of GOMP_critical_name_start, Number of GOMP_critical_start, Number of GOMP_loop_doacross_dynamic_start, Number of GOMP_loop_doacross_guided_start, Number of GOMP_loop_doacross_runtime_start, Number of GOMP_loop_doacross_static_start, Number of GOMP_loop_dynamic_next, Number of GOMP_loop_dynamic_start, Number of GOMP_loop_end, Number of GOMP_loop_end_cancel, Number of GOMP_loop_end_nowait, Number of GOMP_loop_guided_next, Number of GOMP_loop_guided_start, Number of GOMP_loop_nonmonotonic_dynamic_next, Number of GOMP_loop_nonmonotonic_dynamic_start, Number of GOMP_loop_nonmonotonic_guided_next, Number of GOMP_loop_nonmonotonic_guided_start, Number of GOMP_loop_ordered_dynamic_next, Number of GOMP_loop_ordered_dynamic_start, Number of GOMP_loop_ordered_guided_next, Number of GOMP_loop_ordered_guided_start, Number of GOMP_loop_ordered_runtime_next, Number of GOMP_loop_ordered_runtime_start, Number of GOMP_loop_ordered_static_next, Number of GOMP_loop_ordered_static_start, Number of GOMP_loop_runtime_next, Number of GOMP_loop_runtime_start, Number of GOMP_loop_static_next, Number of GOMP_loop_static_start, Number of GOMP_parallel_loop_dynamic, Number of GOMP_parallel_loop_dynamic_start, Number of GOMP_parallel_loop_guided, Number of GOMP_parallel_loop_guided_start, Number of GOMP_parallel_loop_nonmonotonic_dynamic, Number of GOMP_parallel_loop_nonmonotonic_guided, Number of GOMP_parallel_loop_runtime, Number of GOMP_parallel_loop_runtime_start, Number of GOMP_parallel_loop_static, Number of GOMP_parallel_loop_static_start, Number of GOMP_loop_ull_doacross_dynamic_start, Number of GOMP_loop_ull_doacross_guided_start, Number of GOMP_loop_ull_doacross_runtime_start, Number of GOMP_loop_ull_doacross_static_start, Number of GOMP_loop_ull_dynamic_next, Number of GOMP_loop_ull_dynamic_start, Number of GOMP_loop_ull_guided_next, Number of GOMP_loop_ull_guided_start, Number of GOMP_loop_ull_nonmonotonic_dynamic_next, Number of GOMP_loop_ull_nonmonotonic_dynamic_start, Number of GOMP_loop_ull_nonmonotonic_guided_next, Number of GOMP_loop_ull_nonmonotonic_guided_start, Number of GOMP_loop_ull_ordered_dynamic_next, Number of GOMP_loop_ull_ordered_dynamic_start, Number of GOMP_loop_ull_ordered_guided_next, Number of GOMP_loop_ull_ordered_guided_start, Number of GOMP_loop_ull_ordered_runtime_next, Number of GOMP_loop_ull_ordered_runtime_start, Number of GOMP_loop_ull_ordered_static_next, Number of GOMP_loop_ull_ordered_static_start, Number of GOMP_loop_ull_runtime_next, Number of GOMP_loop_ull_runtime_start, Number of GOMP_loop_ull_static_next, Number of GOMP_loop_ull_static_start, Number of GOMP_doacross_post, Number of GOMP_doacross_ull_post, Number of GOMP_doacross_ull_wait, Number of GOMP_doacross_wait, Number of GOMP_ordered_end, Number of GOMP_ordered_start, Number of GOMP_cancel, Number of GOMP_cancellation_point, Number of GOMP_parallel, Number of GOMP_parallel_end, Number of GOMP_parallel_start, Number of GOMP_parallel_sections, Number of GOMP_parallel_sections_start, Number of GOMP_sections_end, Number of GOMP_sections_end_cancel, Number of GOMP_sections_end_nowait, Number of GOMP_sections_next, Number of GOMP_sections_start, Number of GOMP_single_copy_end, Number of GOMP_single_copy_start, Number of GOMP_single_start, Number of GOMP_PLUGIN_target_task_completion, Number of GOMP_task, Number of GOMP_taskgroup_end, Number of GOMP_taskgroup_start, Number of GOMP_taskwait, Number of GOMP_taskyield, Number of GOMP_offload_register, Number of GOMP_offload_register_ver, Number of GOMP_offload_unregister, Number of GOMP_offload_unregister_ver, Number of GOMP_target, Number of GOMP_target_data, Number of GOMP_target_data_ext, Number of GOMP_target_end_data, Number of GOMP_target_enter_exit_data, Number of GOMP_target_ext, Number of GOMP_target_update, Number of GOMP_target_update_ext, Number of GOMP_teams, Number of GOMP_taskloop, Number of GOACC_data_end, Number of GOACC_data_start, Number of GOACC_declare, Number of GOACC_enter_exit_data, Number of GOACC_get_num_threads, Number of GOACC_get_thread_num, Number of GOACC_parallel, Number of GOACC_parallel_keyed, Number of GOACC_update, Number of GOACC_wait\n");
	snprintf(buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer), "%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu", accum_count[idx_GOMP_atomic_end], accum_count[idx_GOMP_atomic_start], accum_count[idx_GOMP_barrier], accum_count[idx_GOMP_barrier_cancel], accum_count[idx_GOMP_critical_end], accum_count[idx_GOMP_critical_name_end], accum_count[idx_GOMP_critical_name_start], accum_count[idx_GOMP_critical_start], accum_count[idx_GOMP_loop_doacross_dynamic_start], accum_count[idx_GOMP_loop_doacross_guided_start], accum_count[idx_GOMP_loop_doacross_runtime_start], accum_count[idx_GOMP_loop_doacross_static_start], accum_count[idx_GOMP_loop_dynamic_next], accum_count[idx_GOMP_loop_dynamic_start], accum_count[idx_GOMP_loop_end], accum_count[idx_GOMP_loop_end_cancel], accum_count[idx_GOMP_loop_end_nowait], accum_count[idx_GOMP_loop_guided_next], accum_count[idx_GOMP_loop_guided_start], accum_count[idx_GOMP_loop_nonmonotonic_dynamic_next], accum_count[idx_GOMP_loop_nonmonotonic_dynamic_start], accum_count[idx_GOMP_loop_nonmonotonic_guided_next], accum_count[idx_GOMP_loop_nonmonotonic_guided_start], accum_count[idx_GOMP_loop_ordered_dynamic_next], accum_count[idx_GOMP_loop_ordered_dynamic_start], accum_count[idx_GOMP_loop_ordered_guided_next], accum_count[idx_GOMP_loop_ordered_guided_start], accum_count[idx_GOMP_loop_ordered_runtime_next], accum_count[idx_GOMP_loop_ordered_runtime_start], accum_count[idx_GOMP_loop_ordered_static_next], accum_count[idx_GOMP_loop_ordered_static_start], accum_count[idx_GOMP_loop_runtime_next], accum_count[idx_GOMP_loop_runtime_start], accum_count[idx_GOMP_loop_static_next], accum_count[idx_GOMP_loop_static_start], accum_count[idx_GOMP_parallel_loop_dynamic], accum_count[idx_GOMP_parallel_loop_dynamic_start], accum_count[idx_GOMP_parallel_loop_guided], accum_count[idx_GOMP_parallel_loop_guided_start], accum_count[idx_GOMP_parallel_loop_nonmonotonic_dynamic], accum_count[idx_GOMP_parallel_loop_nonmonotonic_guided], accum_count[idx_GOMP_parallel_loop_runtime], accum_count[idx_GOMP_parallel_loop_runtime_start], accum_count[idx_GOMP_parallel_loop_static], accum_count[idx_GOMP_parallel_loop_static_start], accum_count[idx_GOMP_loop_ull_doacross_dynamic_start], accum_count[idx_GOMP_loop_ull_doacross_guided_start], accum_count[idx_GOMP_loop_ull_doacross_runtime_start], accum_count[idx_GOMP_loop_ull_doacross_static_start], accum_count[idx_GOMP_loop_ull_dynamic_next], accum_count[idx_GOMP_loop_ull_dynamic_start], accum_count[idx_GOMP_loop_ull_guided_next], accum_count[idx_GOMP_loop_ull_guided_start], accum_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_next], accum_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_start], accum_count[idx_GOMP_loop_ull_nonmonotonic_guided_next], accum_count[idx_GOMP_loop_ull_nonmonotonic_guided_start], accum_count[idx_GOMP_loop_ull_ordered_dynamic_next], accum_count[idx_GOMP_loop_ull_ordered_dynamic_start], accum_count[idx_GOMP_loop_ull_ordered_guided_next], accum_count[idx_GOMP_loop_ull_ordered_guided_start], accum_count[idx_GOMP_loop_ull_ordered_runtime_next], accum_count[idx_GOMP_loop_ull_ordered_runtime_start], accum_count[idx_GOMP_loop_ull_ordered_static_next], accum_count[idx_GOMP_loop_ull_ordered_static_start], accum_count[idx_GOMP_loop_ull_runtime_next], accum_count[idx_GOMP_loop_ull_runtime_start], accum_count[idx_GOMP_loop_ull_static_next], accum_count[idx_GOMP_loop_ull_static_start], accum_count[idx_GOMP_doacross_post], accum_count[idx_GOMP_doacross_ull_post], accum_count[idx_GOMP_doacross_ull_wait], accum_count[idx_GOMP_doacross_wait], accum_count[idx_GOMP_ordered_end], accum_count[idx_GOMP_ordered_start], accum_count[idx_GOMP_cancel], accum_count[idx_GOMP_cancellation_point], accum_count[idx_GOMP_parallel], accum_count[idx_GOMP_parallel_end], accum_count[idx_GOMP_parallel_start], accum_count[idx_GOMP_parallel_sections], accum_count[idx_GOMP_parallel_sections_start], accum_count[idx_GOMP_sections_end], accum_count[idx_GOMP_sections_end_cancel], accum_count[idx_GOMP_sections_end_nowait], accum_count[idx_GOMP_sections_next], accum_count[idx_GOMP_sections_start], accum_count[idx_GOMP_single_copy_end], accum_count[idx_GOMP_single_copy_start], accum_count[idx_GOMP_single_start], accum_count[idx_GOMP_PLUGIN_target_task_completion], accum_count[idx_GOMP_task], accum_count[idx_GOMP_taskgroup_end], accum_count[idx_GOMP_taskgroup_start], accum_count[idx_GOMP_taskwait], accum_count[idx_GOMP_taskyield], accum_count[idx_GOMP_offload_register], accum_count[idx_GOMP_offload_register_ver], accum_count[idx_GOMP_offload_unregister], accum_count[idx_GOMP_offload_unregister_ver], accum_count[idx_GOMP_target], accum_count[idx_GOMP_target_data], accum_count[idx_GOMP_target_data_ext], accum_count[idx_GOMP_target_end_data], accum_count[idx_GOMP_target_enter_exit_data], accum_count[idx_GOMP_target_ext], accum_count[idx_GOMP_target_update], accum_count[idx_GOMP_target_update_ext], accum_count[idx_GOMP_teams], accum_count[idx_GOMP_taskloop], accum_count[idx_GOACC_data_end], accum_count[idx_GOACC_data_start], accum_count[idx_GOACC_declare], accum_count[idx_GOACC_enter_exit_data], accum_count[idx_GOACC_get_num_threads], accum_count[idx_GOACC_get_thread_num], accum_count[idx_GOACC_parallel], accum_count[idx_GOACC_parallel_keyed], accum_count[idx_GOACC_update], accum_count[idx_GOACC_wait]);

	FILE *fout = fopen("accum_results.csv", "w");
	fprintf(fout, buffer);
	fclose(fout);
}

// HOOKS
void PRE_GOMP_atomic_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_atomic_end]++;
}

void POST_GOMP_atomic_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_atomic_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_atomic_start]++;
}

void POST_GOMP_atomic_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_barrier(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_barrier]++;
}

void POST_GOMP_barrier(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_barrier_cancel]++;
}

bool POST_GOMP_barrier_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_critical_end]++;
}

void POST_GOMP_critical_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_critical_name_end]++;
}

void POST_GOMP_critical_name_end(void **pptr)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_critical_name_start]++;
}

void POST_GOMP_critical_name_start(void **pptr)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_critical_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_critical_start]++;
}

void POST_GOMP_critical_start(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_doacross_dynamic_start]++;
}

bool POST_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_doacross_guided_start]++;
}

bool POST_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_doacross_runtime_start]++;
}

bool POST_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_doacross_static_start]++;
}

bool POST_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_dynamic_next]++;
}

bool POST_GOMP_loop_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_dynamic_start]++;
}

bool POST_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_end]++;
}

void POST_GOMP_loop_end(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_end_cancel]++;
}

bool POST_GOMP_loop_end_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_end_nowait]++;
}

void POST_GOMP_loop_end_nowait(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_guided_next]++;
}

bool POST_GOMP_loop_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_guided_start]++;
}

bool POST_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_nonmonotonic_dynamic_next]++;
}

bool POST_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_nonmonotonic_dynamic_start]++;
}

bool POST_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_nonmonotonic_guided_next]++;
}

bool POST_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_nonmonotonic_guided_start]++;
}

bool POST_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_dynamic_next]++;
}

bool POST_GOMP_loop_ordered_dynamic_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_dynamic_start]++;
}

bool POST_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_guided_next]++;
}

bool POST_GOMP_loop_ordered_guided_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_guided_start]++;
}

bool POST_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_runtime_next]++;
}

bool POST_GOMP_loop_ordered_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_runtime_start]++;
}

bool POST_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_static_next]++;
}

bool POST_GOMP_loop_ordered_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ordered_static_start]++;
}

bool POST_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_runtime_next]++;
}

bool POST_GOMP_loop_runtime_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_runtime_start]++;
}

bool POST_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_static_next]++;
}

bool POST_GOMP_loop_static_next(long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_static_start]++;
}

bool POST_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_dynamic]++;
}

void POST_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_dynamic_start]++;
}

void POST_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_guided]++;
}

void POST_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_guided_start]++;
}

void POST_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_nonmonotonic_dynamic]++;
}

void POST_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_nonmonotonic_guided]++;
}

void POST_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_runtime]++;
}

void POST_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_runtime_start]++;
}

void POST_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_static]++;
}

void POST_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_loop_static_start]++;
}

void POST_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_doacross_dynamic_start]++;
}

bool POST_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_doacross_guided_start]++;
}

bool POST_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_doacross_runtime_start]++;
}

bool POST_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_doacross_static_start]++;
}

bool POST_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_dynamic_next]++;
}

bool POST_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_dynamic_start]++;
}

bool POST_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_guided_next]++;
}

bool POST_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_guided_start]++;
}

bool POST_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_next]++;
}

bool POST_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_nonmonotonic_dynamic_start]++;
}

bool POST_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_nonmonotonic_guided_next]++;
}

bool POST_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_nonmonotonic_guided_start]++;
}

bool POST_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_dynamic_next]++;
}

bool POST_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_dynamic_start]++;
}

bool POST_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_guided_next]++;
}

bool POST_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_guided_start]++;
}

bool POST_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_runtime_next]++;
}

bool POST_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_runtime_start]++;
}

bool POST_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_static_next]++;
}

bool POST_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_ordered_static_start]++;
}

bool POST_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_runtime_next]++;
}

bool POST_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_runtime_start]++;
}

bool POST_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_static_next]++;
}

bool POST_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_loop_ull_static_start]++;
}

bool POST_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_doacross_post]++;
}

void POST_GOMP_doacross_post(long *counts)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_doacross_ull_post]++;
}

void POST_GOMP_doacross_ull_post(gomp_ull *counts)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_doacross_ull_wait]++;
}

void POST_GOMP_doacross_ull_wait(gomp_ull first, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_doacross_wait]++;
}

void POST_GOMP_doacross_wait(long first, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_ordered_end]++;
}

void POST_GOMP_ordered_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_ordered_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_ordered_start]++;
}

void POST_GOMP_ordered_start(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_cancel]++;
}

bool POST_GOMP_cancel(int which, bool do_cancel)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_cancellation_point]++;
}

bool POST_GOMP_cancellation_point(int which)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel]++;
}

void POST_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_end]++;
}

void POST_GOMP_parallel_end(void)
{
	PRINT_FUNC_NAME;
	print_results_csv_partial();
	int i;
	for (i = 0; i < NUM_FUNCTIONS; i++)
	{
		accum_count[i] += partial_count[i];
		partial_count[i] = 0;
	}
	print_results_csv_accum();
}

void PRE_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_start]++;
}

void POST_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_sections]++;
}

void POST_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_parallel_sections_start]++;
}

void POST_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_sections_end]++;
}

void POST_GOMP_sections_end(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_sections_end_cancel]++;
}

bool POST_GOMP_sections_end_cancel(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_sections_end_nowait]++;
}

void POST_GOMP_sections_end_nowait(void)
{
	PRINT_FUNC_NAME;
}

unsigned PRE_GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_sections_next]++;
}

unsigned POST_GOMP_sections_next(void)
{
	PRINT_FUNC_NAME;
}

unsigned PRE_GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_sections_start]++;
}

unsigned POST_GOMP_sections_start(unsigned count)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_single_copy_end(void *data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_single_copy_end]++;
}

void POST_GOMP_single_copy_end(void *data)
{
	PRINT_FUNC_NAME;
}

void *PRE_GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_single_copy_start]++;
}

void *POST_GOMP_single_copy_start(void)
{
	PRINT_FUNC_NAME;
}

bool PRE_GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_single_start]++;
}

bool POST_GOMP_single_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_PLUGIN_target_task_completion(void *data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_PLUGIN_target_task_completion]++;
}

void POST_GOMP_PLUGIN_target_task_completion(void *data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_task]++;
}

void POST_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_taskgroup_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_taskgroup_end]++;
}

void POST_GOMP_taskgroup_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_taskgroup_start(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_taskgroup_start]++;
}

void POST_GOMP_taskgroup_start(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_taskwait(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_taskwait]++;
}

void POST_GOMP_taskwait(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_taskyield(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_taskyield]++;
}

void POST_GOMP_taskyield(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_offload_register]++;
}

void POST_GOMP_offload_register(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_offload_register_ver]++;
}

void POST_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_offload_unregister]++;
}

void POST_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_offload_unregister_ver]++;
}

void POST_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target]++;
}

void POST_GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_data]++;
}

void POST_GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_data_ext]++;
}

void POST_GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_end_data(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_end_data]++;
}

void POST_GOMP_target_end_data(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_enter_exit_data]++;
}

void POST_GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_ext]++;
}

void POST_GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_update]++;
}

void POST_GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_target_update_ext]++;
}

void POST_GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_teams(unsigned int num_teams, unsigned int thread_limit)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_teams]++;
}

void POST_GOMP_teams(unsigned int num_teams, unsigned int thread_limit)
{
	PRINT_FUNC_NAME;
}

void PRE_GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOMP_taskloop]++;
}

void POST_GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_data_end(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_data_end]++;
}

void POST_GOACC_data_end(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_data_start]++;
}

void POST_GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_declare]++;
}

void POST_GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_enter_exit_data]++;
}

void POST_GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
}

int PRE_GOACC_get_num_threads(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_get_num_threads]++;
}

int POST_GOACC_get_num_threads(void)
{
	PRINT_FUNC_NAME;
}

int PRE_GOACC_get_thread_num(void)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_get_thread_num]++;
}

int POST_GOACC_get_thread_num(void)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_parallel]++;
}

void POST_GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_parallel_keyed]++;
}

void POST_GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_update]++;
}

void POST_GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
}

void PRE_GOACC_wait(int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
	partial_count[idx_GOACC_wait]++;
}

void POST_GOACC_wait(int async, int num_waits, ...)
{
	PRINT_FUNC_NAME;
}

///GENERATED 120 FUNCTIONS
