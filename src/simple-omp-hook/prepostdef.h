
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

    void PRE_GOMP_atomic_end(void);
    void POST_GOMP_atomic_end(void);

    void PRE_GOMP_atomic_start(void);
    void POST_GOMP_atomic_start(void);

    /* barrier.c */

    void PRE_GOMP_barrier(void);
    void POST_GOMP_barrier(void);

    bool PRE_GOMP_barrier_cancel(void);
    bool POST_GOMP_barrier_cancel(void);

    /* critical.c */

    void PRE_GOMP_critical_end(void);
    void POST_GOMP_critical_end(void);

    void PRE_GOMP_critical_name_end(void **pptr);
    void POST_GOMP_critical_name_end(void **pptr);

    void PRE_GOMP_critical_name_start(void **pptr);
    void POST_GOMP_critical_name_start(void **pptr);

    void PRE_GOMP_critical_start(void);
    void POST_GOMP_critical_start(void);

    /* loop.c */

    bool PRE_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_doacross_dynamic_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_doacross_guided_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);
    bool POST_GOMP_loop_doacross_runtime_start(unsigned ncounts, long *counts, long *istart, long *iend);

    bool PRE_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_doacross_static_start(unsigned ncounts, long *counts, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_dynamic_next(long *istart, long *iend);
    bool POST_GOMP_loop_dynamic_next(long *istart, long *iend);

    bool PRE_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    void PRE_GOMP_loop_end(void);
    void POST_GOMP_loop_end(void);

    bool PRE_GOMP_loop_end_cancel(void);
    bool POST_GOMP_loop_end_cancel(void);

    void PRE_GOMP_loop_end_nowait(void);
    void POST_GOMP_loop_end_nowait(void);

    bool PRE_GOMP_loop_guided_next(long *istart, long *iend);
    bool POST_GOMP_loop_guided_next(long *istart, long *iend);

    bool PRE_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);
    bool POST_GOMP_loop_nonmonotonic_dynamic_next(long *istart, long *iend);

    bool PRE_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_nonmonotonic_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);
    bool POST_GOMP_loop_nonmonotonic_guided_next(long *istart, long *iend);

    bool PRE_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_nonmonotonic_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_dynamic_next(long *istart, long *iend);
    bool POST_GOMP_loop_ordered_dynamic_next(long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_ordered_dynamic_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_guided_next(long *istart, long *iend);
    bool POST_GOMP_loop_ordered_guided_next(long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_ordered_guided_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_runtime_next(long *istart, long *iend);
    bool POST_GOMP_loop_ordered_runtime_next(long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);
    bool POST_GOMP_loop_ordered_runtime_start(long start, long end, long incr, long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_static_next(long *istart, long *iend);
    bool POST_GOMP_loop_ordered_static_next(long *istart, long *iend);

    bool PRE_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_ordered_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    bool PRE_GOMP_loop_runtime_next(long *istart, long *iend);
    bool POST_GOMP_loop_runtime_next(long *istart, long *iend);

    bool PRE_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);
    bool POST_GOMP_loop_runtime_start(long start, long end, long incr, long *istart, long *iend);

    bool PRE_GOMP_loop_static_next(long *istart, long *iend);
    bool POST_GOMP_loop_static_next(long *istart, long *iend);

    bool PRE_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);
    bool POST_GOMP_loop_static_start(long start, long end, long incr, long chunk_size, long *istart, long *iend);

    void PRE_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
    void POST_GOMP_parallel_loop_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

    void PRE_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
    void POST_GOMP_parallel_loop_dynamic_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

    void PRE_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
    void POST_GOMP_parallel_loop_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

    void PRE_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
    void POST_GOMP_parallel_loop_guided_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

    void PRE_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
    void POST_GOMP_parallel_loop_nonmonotonic_dynamic(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

    void PRE_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
    void POST_GOMP_parallel_loop_nonmonotonic_guided(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

    void PRE_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);
    void POST_GOMP_parallel_loop_runtime(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, unsigned flags);

    void PRE_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);
    void POST_GOMP_parallel_loop_runtime_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr);

    void PRE_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);
    void POST_GOMP_parallel_loop_static(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size, unsigned flags);

    void PRE_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);
    void POST_GOMP_parallel_loop_static_start(void (*fn)(void *), void *data, unsigned num_threads, long start, long end, long incr, long chunk_size);

    /* loop_ull.c */

    bool PRE_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_doacross_dynamic_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_doacross_guided_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_doacross_runtime_start(unsigned ncounts, gomp_ull *counts, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_doacross_static_start(unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_dynamic_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_guided_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_nonmonotonic_dynamic_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_nonmonotonic_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_nonmonotonic_guided_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_nonmonotonic_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_dynamic_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_dynamic_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_guided_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_guided_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_runtime_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_static_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_ordered_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_runtime_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_runtime_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_static_next(gomp_ull *istart, gomp_ull *iend);

    bool PRE_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);
    bool POST_GOMP_loop_ull_static_start(bool up, gomp_ull start, gomp_ull end, gomp_ull incr, gomp_ull chunk_size, gomp_ull *istart, gomp_ull *iend);

    /* ordered.c */

    void PRE_GOMP_doacross_post(long *counts);
    void POST_GOMP_doacross_post(long *counts);

    void PRE_GOMP_doacross_ull_post(gomp_ull *counts);
    void POST_GOMP_doacross_ull_post(gomp_ull *counts);

    void PRE_GOMP_doacross_ull_wait(gomp_ull first, ...);
    void POST_GOMP_doacross_ull_wait(gomp_ull first, ...);

    void PRE_GOMP_doacross_wait(long first, ...);
    void POST_GOMP_doacross_wait(long first, ...);

    void PRE_GOMP_ordered_end(void);
    void POST_GOMP_ordered_end(void);

    void PRE_GOMP_ordered_start(void);
    void POST_GOMP_ordered_start(void);

    /* parallel.c */

    bool PRE_GOMP_cancel(int which, bool do_cancel);
    bool POST_GOMP_cancel(int which, bool do_cancel);

    bool PRE_GOMP_cancellation_point(int which);
    bool POST_GOMP_cancellation_point(int which);

    void PRE_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);
    void POST_GOMP_parallel(void (*fn)(void *), void *data, unsigned num_threads, unsigned int flags);

    void PRE_GOMP_parallel_end(void);
    void POST_GOMP_parallel_end(void);

    void PRE_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);
    void POST_GOMP_parallel_start(void (*fn)(void *), void *data, unsigned num_threads);

    /* sections.c */

    void PRE_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);
    void POST_GOMP_parallel_sections(void (*fn)(void *), void *data, unsigned num_threads, unsigned count, unsigned flags);

    void PRE_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);
    void POST_GOMP_parallel_sections_start(void (*fn)(void *), void *data, unsigned num_threads, unsigned count);

    void PRE_GOMP_sections_end(void);
    void POST_GOMP_sections_end(void);

    bool PRE_GOMP_sections_end_cancel(void);
    bool POST_GOMP_sections_end_cancel(void);

    void PRE_GOMP_sections_end_nowait(void);
    void POST_GOMP_sections_end_nowait(void);

    unsigned PRE_GOMP_sections_next(void);
    unsigned POST_GOMP_sections_next(void);

    unsigned PRE_GOMP_sections_start(unsigned count);
    unsigned POST_GOMP_sections_start(unsigned count);

    /* single.c */

    void PRE_GOMP_single_copy_end(void *data);
    void POST_GOMP_single_copy_end(void *data);

    void *PRE_GOMP_single_copy_start(void);
    void *POST_GOMP_single_copy_start(void);

    bool PRE_GOMP_single_start(void);
    bool POST_GOMP_single_start(void);

    /* task.c */

    void PRE_GOMP_PLUGIN_target_task_completion(void *data);
    void POST_GOMP_PLUGIN_target_task_completion(void *data);

    void PRE_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);
    void POST_GOMP_task(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, bool if_clause, unsigned flags, void **depend, int priority);

    void PRE_GOMP_taskgroup_end(void);
    void POST_GOMP_taskgroup_end(void);

    void PRE_GOMP_taskgroup_start(void);
    void POST_GOMP_taskgroup_start(void);

    void PRE_GOMP_taskwait(void);
    void POST_GOMP_taskwait(void);

    void PRE_GOMP_taskyield(void);
    void POST_GOMP_taskyield(void);

    /* target.c */

    void PRE_GOMP_offload_register(const void *host_table, int target_type, const void *target_data);
    void POST_GOMP_offload_register(const void *host_table, int target_type, const void *target_data);

    void PRE_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
    void POST_GOMP_offload_register_ver(unsigned version, const void *host_table, int target_type, const void *target_data);

    void PRE_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data);
    void POST_GOMP_offload_unregister(const void *host_table, int target_type, const void *target_data);

    void PRE_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data);
    void POST_GOMP_offload_unregister_ver(unsigned version, const void *host_table, int target_type, const void *target_data);

    void PRE_GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
    void POST_GOMP_target(int device, void (*fn)(void *), const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);

    void PRE_GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
    void POST_GOMP_target_data(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);

    void PRE_GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
    void POST_GOMP_target_data_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);

    void PRE_GOMP_target_end_data(void);
    void POST_GOMP_target_end_data(void);

    void PRE_GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
    void POST_GOMP_target_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);

    void PRE_GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);
    void POST_GOMP_target_ext(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend, void **args);

    void PRE_GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);
    void POST_GOMP_target_update(int device, const void *unused, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned char *kinds);

    void PRE_GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);
    void POST_GOMP_target_update_ext(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, unsigned int flags, void **depend);

    void PRE_GOMP_teams(unsigned int num_teams, unsigned int thread_limit);
    void POST_GOMP_teams(unsigned int num_teams, unsigned int thread_limit);

    /* taskloop.c */

    void PRE_GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step);
    void POST_GOMP_taskloop(void (*fn)(void *), void *data, void (*cpyfn)(void *, void *), long arg_size, long arg_align, unsigned flags, unsigned long num_tasks, int priority, TYPE start, TYPE end, TYPE step);

    /* oacc-parallel.c */

    void PRE_GOACC_data_end(void);
    void POST_GOACC_data_end(void);

    void PRE_GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
    void POST_GOACC_data_start(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);

    void PRE_GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);
    void POST_GOACC_declare(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds);

    void PRE_GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
    void POST_GOACC_enter_exit_data(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);

    int PRE_GOACC_get_num_threads(void);
    int POST_GOACC_get_num_threads(void);

    int PRE_GOACC_get_thread_num(void);
    int POST_GOACC_get_thread_num(void);

    void PRE_GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...);
    void POST_GOACC_parallel(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int num_gangs, int num_workers, int vector_length, int async, int num_waits, ...);

    void PRE_GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...);
    void POST_GOACC_parallel_keyed(int device, void (*fn)(void *), size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, ...);

    void PRE_GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);
    void POST_GOACC_update(int device, size_t mapnum, void **hostaddrs, size_t *sizes, unsigned short *kinds, int async, int num_waits, ...);

    void PRE_GOACC_wait(int async, int num_waits, ...);
    void POST_GOACC_wait(int async, int num_waits, ...);

    ///GENERATED 120 FUNCTIONS

#ifdef __cplusplus
}
#endif

#endif /* PREPOSTDEF_H */
