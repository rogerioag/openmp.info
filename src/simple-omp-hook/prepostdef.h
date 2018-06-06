
#ifndef PREPOSTDEF_H
#define PREPOSTDEF_H

#define PREPOSTDEF 1

typedef unsigned long long gomp_ull;
typedef long TYPE;

#ifdef __cplusplus
extern "C"
{
#endif

	/* atomic.c */

	void PRE_GOMP_atomic_start(void);
	void POST_GOMP_atomic_start(void);

	void PRE_GOMP_atomic_end(void);
	void POST_GOMP_atomic_end(void);

	/* barrier.c */
	void PRE_GOMP_barrier(void);
	void POST_GOMP_barrier(void);

	bool PRE_GOMP_barrier_cancel(void);
	bool POST_GOMP_barrier_cancel(void);

	/* critical.c */
	void PRE_GOMP_critical_start(void);
	void POST_GOMP_critical_start(void);

	void PRE_GOMP_critical_end(void);
	void POST_GOMP_critical_end(void);

	void PRE_GOMP_critical_name_start(void **pptr);
	void POST_GOMP_critical_name_start(void **pptr);

	void PRE_GOMP_critical_name_end(void **pptr);
	void POST_GOMP_critical_name_end(void **pptr);

	/* loop.c */
	bool PRE_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool POST_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);
	bool POST_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);

	bool PRE_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);
	bool POST_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);

	bool PRE_GOMP_loop_runtime_next(long *istart, long *iend);
	bool POST_GOMP_loop_runtime_next(long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_runtime_next(long *istart, long *iend);
	bool POST_GOMP_loop_ordered_runtime_next(long *istart, long *iend);

	void PRE_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void POST_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

	void PRE_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void POST_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

	void PRE_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
	void POST_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

	void PRE_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
	void POST_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);

	void PRE_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void POST_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

	void PRE_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void POST_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

	void PRE_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void POST_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

	void PRE_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void POST_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

	void PRE_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
	void POST_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

	void PRE_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
	void POST_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);

	void PRE_GOMP_loop_end(void);
	void POST_GOMP_loop_end(void);

	bool PRE_GOMP_loop_end_cancel(void);
	bool POST_GOMP_loop_end_cancel(void);

	void PRE_GOMP_loop_end_nowait(void);
	void POST_GOMP_loop_end_nowait(void);

	bool PRE_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
	bool POST_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

	bool PRE_GOMP_loop_static_next(long *istart, long *iend);
	bool POST_GOMP_loop_static_next(long *istart, long *iend);

	bool PRE_GOMP_loop_dynamic_next(long *istart, long *iend);
	bool POST_GOMP_loop_dynamic_next(long *istart, long *iend);

	bool PRE_GOMP_loop_guided_next(long *istart, long *iend);
	bool POST_GOMP_loop_guided_next(long *istart, long *iend);

	bool PRE_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);
	bool POST_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);

	bool PRE_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);
	bool POST_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_static_next(long *istart, long *iend);
	bool POST_GOMP_loop_ordered_static_next(long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_dynamic_next(long *istart, long *iend);
	bool POST_GOMP_loop_ordered_dynamic_next(long *istart, long *iend);

	bool PRE_GOMP_loop_ordered_guided_next(long *istart, long *iend);
	bool POST_GOMP_loop_ordered_guided_next(long *istart, long *iend);

	/* loop_ull.c */
	bool PRE_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);

	bool PRE_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);
	bool POST_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);

	/* ordered.c */
	void PRE_GOMP_ordered_start(void);
	void POST_GOMP_ordered_start(void);

	void PRE_GOMP_ordered_end(void);
	void POST_GOMP_ordered_end(void);

	void PRE_GOMP_doacross_post(long *counts);
	void POST_GOMP_doacross_post(long *counts);

	void PRE_GOMP_doacross_wait(long first, ...);
	void POST_GOMP_doacross_wait(long first, ...);

	void PRE_GOMP_doacross_ull_post(gomp_ull *counts);
	void POST_GOMP_doacross_ull_post(gomp_ull *counts);

	void PRE_GOMP_doacross_ull_wait(gomp_ull first, ...);
	void POST_GOMP_doacross_ull_wait(gomp_ull first, ...);

	/* parallel.c */
	void PRE_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);
	void POST_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);

	void PRE_GOMP_parallel_end(void);
	void POST_GOMP_parallel_end(void);

	void PRE_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
	void POST_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);

	bool PRE_GOMP_cancellation_point(int which);
	bool POST_GOMP_cancellation_point(int which);

	bool PRE_GOMP_cancel(int which, bool do_cancel);
	bool POST_GOMP_cancel(int which, bool do_cancel);

	/* sections.c */
	unsigned PRE_GOMP_sections_start(unsigned count);
	unsigned POST_GOMP_sections_start(unsigned count);

	unsigned PRE_GOMP_sections_next(void);
	unsigned POST_GOMP_sections_next(void);

	void PRE_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
	void POST_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);

	void PRE_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
	void POST_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);

	void PRE_GOMP_sections_end(void);
	void POST_GOMP_sections_end(void);

	bool PRE_GOMP_sections_end_cancel(void);
	bool POST_GOMP_sections_end_cancel(void);

	void PRE_GOMP_sections_end_nowait(void);
	void POST_GOMP_sections_end_nowait(void);

	/* single.c */
	bool PRE_GOMP_single_start(void);
	bool POST_GOMP_single_start(void);

	void PRE_GOMP_single_copy_start(void);
	void POST_GOMP_single_copy_start(void);

	void PRE_GOMP_single_copy_end(void *data);
	void POST_GOMP_single_copy_end(void *data);

	/* task.c */
	void PRE_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);
	void POST_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);

	void PRE_GOMP_PLUGIN_target_task_completion(void *data);
	void POST_GOMP_PLUGIN_target_task_completion(void *data);

	void PRE_GOMP_taskwait(void);
	void POST_GOMP_taskwait(void);

	void PRE_GOMP_taskyield(void);
	void POST_GOMP_taskyield(void);

	void PRE_GOMP_taskgroup_start(void);
	void POST_GOMP_taskgroup_start(void);

	void PRE_GOMP_taskgroup_end(void);
	void POST_GOMP_taskgroup_end(void);

	/* target.c */
	void PRE_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
	void POST_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data);

	void PRE_GOMP_offload_register(const void *host_table, int target_type, const void *target_data);
	void POST_GOMP_offload_register(const void *host_table, int target_type, const void *target_data);

	void PRE_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
	void POST_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data);

	void PRE_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data);
	void POST_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data);

	void PRE_GOMP_target(int device, void (*fn)(void *), const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);
	void POST_GOMP_target(int device, void (*fn)(void *), const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);

	void PRE_GOMP_target_ext(int device, void (*fn)(void *), unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);
	void POST_GOMP_target_ext(int device, void (*fn)(void *), unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);

	void PRE_GOMP_target_data(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);
	void POST_GOMP_target_data(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);

	void PRE_GOMP_target_data_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds);
	void POST_GOMP_target_data_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds);

	void PRE_GOMP_target_end_data(void);
	void POST_GOMP_target_end_data(void);

	void PRE_GOMP_target_update(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);
	void POST_GOMP_target_update(int device, const void *unused, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned char *kinds);

	void PRE_GOMP_target_update_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend);
	void POST_GOMP_target_update_ext(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend);

	void PRE_GOMP_target_enter_exit_data(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend);
	void POST_GOMP_target_enter_exit_data(int device, unsigned int mapnum, void **hostaddrs, unsigned int *sizes, unsigned short *kinds, unsigned int flags, void **depend);

	void PRE_GOMP_teams(unsigned int num_teams, unsigned int thread_limit);
	void POST_GOMP_teams(unsigned int num_teams, unsigned int thread_limit);

#ifdef __cplusplus
}
#endif

#endif /* PREPOSTDEF_H */
