/* Copyright (C) 2005-2018 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU Offloading and Multi Processing Library
   (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* This file handles the LOOP (FOR/DO) construct.  */



/* Initialize the given work share construct from the given arguments.  */

static inline void
gomp_loop_init (struct gomp_work_share *ws, long start, long end, long incr,
		enum gomp_schedule_type sched, long chunk_size)
{
}

/* The *_start routines are called when first encountering a loop construct
   that is not bound directly to a parallel construct.  The first thread 
   that arrives will create the work-share construct; subsequent threads
   will see the construct exists and allocate work from it.

   START, END, INCR are the bounds of the loop; due to the restrictions of
   OpenMP, these values must be the same in every thread.  This is not 
   verified (nor is it entirely verifiable, since START is not necessarily
   retained intact in the work-share data structure).  CHUNK_SIZE is the
   scheduling parameter; again this must be identical in all threads.

   Returns true if there's any work for this thread to perform.  If so,
   *ISTART and *IEND are filled with the bounds of the iteration block
   allocated to this thread.  Returns false if all work was assigned to
   other threads prior to this thread's arrival.  */

static _Bool
gomp_loop_static_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend)
{
}

/* The current dynamic implementation is always monotonic.  The
   entrypoints without nonmonotonic in them have to be always monotonic,
   but the nonmonotonic ones could be changed to use work-stealing for
   improved scalability.  */

static _Bool
gomp_loop_dynamic_start (long start, long end, long incr, long chunk_size,
			 long *istart, long *iend)
{
}

/* Similarly as for dynamic, though the question is how can the chunk sizes
   be decreased without a central locking or atomics.  */

static _Bool
gomp_loop_guided_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend)
{
}

_Bool
GOMP_loop_runtime_start (long start, long end, long incr,
			 long *istart, long *iend)
{
}

/* The *_ordered_*_start routines are similar.  The only difference is that
   this work-share construct is initialized to expect an ORDERED section.  */

static _Bool
gomp_loop_ordered_static_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend)
{
}

static _Bool
gomp_loop_ordered_dynamic_start (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend)
{
}

static _Bool
gomp_loop_ordered_guided_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_runtime_start (long start, long end, long incr,
				 long *istart, long *iend)
{
}

/* The *_doacross_*_start routines are similar.  The only difference is that
   this work-share construct is initialized to expect an ORDERED(N) - DOACROSS
   section, and the worksharing loop iterates always from 0 to COUNTS[0] - 1
   and other COUNTS array elements tell the library number of iterations
   in the ordered inner loops.  */

static _Bool
gomp_loop_doacross_static_start (unsigned ncounts, long *counts,
				 long chunk_size, long *istart, long *iend)
{
}

static _Bool
gomp_loop_doacross_dynamic_start (unsigned ncounts, long *counts,
				  long chunk_size, long *istart, long *iend)
{
}

static _Bool
gomp_loop_doacross_guided_start (unsigned ncounts, long *counts,
				 long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_doacross_runtime_start (unsigned ncounts, long *counts,
				  long *istart, long *iend)
{
}

/* The *_next routines are called when the thread completes processing of 
   the iteration block currently assigned to it.  If the work-share 
   construct is bound directly to a parallel construct, then the iteration
   bounds may have been set up before the parallel.  In which case, this
   may be the first iteration for the thread.

   Returns true if there is work remaining to be performed; *ISTART and
   *IEND are filled with a new iteration block.  Returns false if all work
   has been assigned.  */

static _Bool
gomp_loop_static_next (long *istart, long *iend)
{
}

static _Bool
gomp_loop_dynamic_next (long *istart, long *iend)
{
}

static _Bool
gomp_loop_guided_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_runtime_next (long *istart, long *iend)
{
}

/* The *_ordered_*_next routines are called when the thread completes
   processing of the iteration block currently assigned to it.

   Returns true if there is work remaining to be performed; *ISTART and
   *IEND are filled with a new iteration block.  Returns false if all work
   has been assigned.  */

static _Bool
gomp_loop_ordered_static_next (long *istart, long *iend)
{
}

static _Bool
gomp_loop_ordered_dynamic_next (long *istart, long *iend)
{
}

static _Bool
gomp_loop_ordered_guided_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_runtime_next (long *istart, long *iend)
{
}

/* The GOMP_parallel_loop_* routines pre-initialize a work-share construct
   to avoid one synchronization once we get into the loop.  */

static void
gomp_parallel_loop_start (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, enum gomp_schedule_type sched,
			  long chunk_size, unsigned int flags)
{
}

void
GOMP_parallel_loop_static_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size)
{
}

void
GOMP_parallel_loop_dynamic_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size)
{
}

void
GOMP_parallel_loop_guided_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size)
{
}

void
GOMP_parallel_loop_runtime_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr)
{
}


void
GOMP_parallel_loop_static (void (*fn) (void *), void *data,
			   unsigned num_threads, long start, long end,
			   long incr, long chunk_size, unsigned flags)
{
}

void
GOMP_parallel_loop_dynamic (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, long chunk_size, unsigned flags)
{
}

void
GOMP_parallel_loop_guided (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, long chunk_size, unsigned flags)
{
}

extern __typeof(GOMP_parallel_loop_dynamic) GOMP_parallel_loop_nonmonotonic_dynamic
	__attribute__((alias ("GOMP_parallel_loop_dynamic")));
extern __typeof(GOMP_parallel_loop_guided) GOMP_parallel_loop_nonmonotonic_guided
	__attribute__((alias ("GOMP_parallel_loop_guided")));
void
GOMP_parallel_loop_nonmonotonic_dynamic (void (*fn) (void *), void *data,
					 unsigned num_threads, long start,
					 long end, long incr, long chunk_size,
					 unsigned flags)
{
}

void
GOMP_parallel_loop_nonmonotonic_guided (void (*fn) (void *), void *data,
					unsigned num_threads, long start,
					long end, long incr, long chunk_size,
					unsigned flags)
{
}

void
GOMP_parallel_loop_runtime (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, unsigned flags)
{
}

/* The GOMP_loop_end* routines are called after the thread is told that
   all loop iterations are complete.  The first two versions synchronize
   all threads; the nowait version does not.  */

void
GOMP_loop_end (void)
{
}

_Bool
GOMP_loop_end_cancel (void)
{
}

void
GOMP_loop_end_nowait (void)
{
}


/* We use static functions above so that we're sure that the "runtime"
   function can defer to the proper routine without interposition.  We
   export the static function with a strong alias when possible, or with
   a wrapper function otherwise.  */

extern __typeof(gomp_loop_static_start) GOMP_loop_static_start
	__attribute__((alias ("gomp_loop_static_start")));
extern __typeof(gomp_loop_dynamic_start) GOMP_loop_dynamic_start
	__attribute__((alias ("gomp_loop_dynamic_start")));
extern __typeof(gomp_loop_guided_start) GOMP_loop_guided_start
	__attribute__((alias ("gomp_loop_guided_start")));
extern __typeof(gomp_loop_dynamic_start) GOMP_loop_nonmonotonic_dynamic_start
	__attribute__((alias ("gomp_loop_dynamic_start")));
extern __typeof(gomp_loop_guided_start) GOMP_loop_nonmonotonic_guided_start
	__attribute__((alias ("gomp_loop_guided_start")));

extern __typeof(gomp_loop_ordered_static_start) GOMP_loop_ordered_static_start
	__attribute__((alias ("gomp_loop_ordered_static_start")));
extern __typeof(gomp_loop_ordered_dynamic_start) GOMP_loop_ordered_dynamic_start
	__attribute__((alias ("gomp_loop_ordered_dynamic_start")));
extern __typeof(gomp_loop_ordered_guided_start) GOMP_loop_ordered_guided_start
	__attribute__((alias ("gomp_loop_ordered_guided_start")));

extern __typeof(gomp_loop_doacross_static_start) GOMP_loop_doacross_static_start
	__attribute__((alias ("gomp_loop_doacross_static_start")));
extern __typeof(gomp_loop_doacross_dynamic_start) GOMP_loop_doacross_dynamic_start
	__attribute__((alias ("gomp_loop_doacross_dynamic_start")));
extern __typeof(gomp_loop_doacross_guided_start) GOMP_loop_doacross_guided_start
	__attribute__((alias ("gomp_loop_doacross_guided_start")));

extern __typeof(gomp_loop_static_next) GOMP_loop_static_next
	__attribute__((alias ("gomp_loop_static_next")));
extern __typeof(gomp_loop_dynamic_next) GOMP_loop_dynamic_next
	__attribute__((alias ("gomp_loop_dynamic_next")));
extern __typeof(gomp_loop_guided_next) GOMP_loop_guided_next
	__attribute__((alias ("gomp_loop_guided_next")));
extern __typeof(gomp_loop_dynamic_next) GOMP_loop_nonmonotonic_dynamic_next
	__attribute__((alias ("gomp_loop_dynamic_next")));
extern __typeof(gomp_loop_guided_next) GOMP_loop_nonmonotonic_guided_next
	__attribute__((alias ("gomp_loop_guided_next")));

extern __typeof(gomp_loop_ordered_static_next) GOMP_loop_ordered_static_next
	__attribute__((alias ("gomp_loop_ordered_static_next")));
extern __typeof(gomp_loop_ordered_dynamic_next) GOMP_loop_ordered_dynamic_next
	__attribute__((alias ("gomp_loop_ordered_dynamic_next")));
extern __typeof(gomp_loop_ordered_guided_next) GOMP_loop_ordered_guided_next
	__attribute__((alias ("gomp_loop_ordered_guided_next")));
_Bool
GOMP_loop_static_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend)
{
}

_Bool
GOMP_loop_dynamic_start (long start, long end, long incr, long chunk_size,
			 long *istart, long *iend)
{
}

_Bool
GOMP_loop_guided_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend)
{
}

_Bool
GOMP_loop_nonmonotonic_dynamic_start (long start, long end, long incr,
				      long chunk_size, long *istart,
				      long *iend)
{
}

_Bool
GOMP_loop_nonmonotonic_guided_start (long start, long end, long incr,
				     long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_static_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_dynamic_start (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_guided_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_doacross_static_start (unsigned ncounts, long *counts,
				 long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_doacross_dynamic_start (unsigned ncounts, long *counts,
				  long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_doacross_guided_start (unsigned ncounts, long *counts,
				 long chunk_size, long *istart, long *iend)
{
}

_Bool
GOMP_loop_static_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_dynamic_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_guided_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_nonmonotonic_dynamic_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_nonmonotonic_guided_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_static_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_dynamic_next (long *istart, long *iend)
{
}

_Bool
GOMP_loop_ordered_guided_next (long *istart, long *iend)
{
}
