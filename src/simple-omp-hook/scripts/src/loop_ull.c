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


typedef unsigned long long gomp_ull;

/* Initialize the given work share construct from the given arguments.  */

static inline void
gomp_loop_ull_init (struct gomp_work_share *ws, _Bool up, gomp_ull start,
		    gomp_ull end, gomp_ull incr, enum gomp_schedule_type sched,
		    gomp_ull chunk_size)
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
gomp_loop_ull_static_start (_Bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_dynamic_start (_Bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull chunk_size,
			     gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_guided_start (_Bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_runtime_start (_Bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
}

/* The *_ordered_*_start routines are similar.  The only difference is that
   this work-share construct is initialized to expect an ORDERED section.  */

static _Bool
gomp_loop_ull_ordered_static_start (_Bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_ordered_dynamic_start (_Bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull chunk_size,
				     gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_ordered_guided_start (_Bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_runtime_start (_Bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull *istart,
				     gomp_ull *iend)
{
}

/* The *_doacross_*_start routines are similar.  The only difference is that
   this work-share construct is initialized to expect an ORDERED(N) - DOACROSS
   section, and the worksharing loop iterates always from 0 to COUNTS[0] - 1
   and other COUNTS array elements tell the library number of iterations
   in the ordered inner loops.  */

static _Bool
gomp_loop_ull_doacross_static_start (unsigned ncounts, gomp_ull *counts,
				     gomp_ull chunk_size, gomp_ull *istart,
				     gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_doacross_dynamic_start (unsigned ncounts, gomp_ull *counts,
				      gomp_ull chunk_size, gomp_ull *istart,
				      gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_doacross_guided_start (unsigned ncounts, gomp_ull *counts,
				     gomp_ull chunk_size, gomp_ull *istart,
				     gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_doacross_runtime_start (unsigned ncounts, gomp_ull *counts,
				      gomp_ull *istart, gomp_ull *iend)
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
gomp_loop_ull_static_next (gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_guided_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_runtime_next (gomp_ull *istart, gomp_ull *iend)
{
}

/* The *_ordered_*_next routines are called when the thread completes
   processing of the iteration block currently assigned to it.

   Returns true if there is work remaining to be performed; *ISTART and
   *IEND are filled with a new iteration block.  Returns false if all work
   has been assigned.  */

static _Bool
gomp_loop_ull_ordered_static_next (gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_ordered_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
}

static _Bool
gomp_loop_ull_ordered_guided_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_runtime_next (gomp_ull *istart, gomp_ull *iend)
{
}

/* We use static functions above so that we're sure that the "runtime"
   function can defer to the proper routine without interposition.  We
   export the static function with a strong alias when possible, or with
   a wrapper function otherwise.  */

extern __typeof(gomp_loop_ull_static_start) GOMP_loop_ull_static_start
	__attribute__((alias ("gomp_loop_ull_static_start")));
extern __typeof(gomp_loop_ull_dynamic_start) GOMP_loop_ull_dynamic_start
	__attribute__((alias ("gomp_loop_ull_dynamic_start")));
extern __typeof(gomp_loop_ull_guided_start) GOMP_loop_ull_guided_start
	__attribute__((alias ("gomp_loop_ull_guided_start")));
extern __typeof(gomp_loop_ull_dynamic_start) GOMP_loop_ull_nonmonotonic_dynamic_start
	__attribute__((alias ("gomp_loop_ull_dynamic_start")));
extern __typeof(gomp_loop_ull_guided_start) GOMP_loop_ull_nonmonotonic_guided_start
	__attribute__((alias ("gomp_loop_ull_guided_start")));

extern __typeof(gomp_loop_ull_ordered_static_start) GOMP_loop_ull_ordered_static_start
	__attribute__((alias ("gomp_loop_ull_ordered_static_start")));
extern __typeof(gomp_loop_ull_ordered_dynamic_start) GOMP_loop_ull_ordered_dynamic_start
	__attribute__((alias ("gomp_loop_ull_ordered_dynamic_start")));
extern __typeof(gomp_loop_ull_ordered_guided_start) GOMP_loop_ull_ordered_guided_start
	__attribute__((alias ("gomp_loop_ull_ordered_guided_start")));

extern __typeof(gomp_loop_ull_doacross_static_start) GOMP_loop_ull_doacross_static_start
	__attribute__((alias ("gomp_loop_ull_doacross_static_start")));
extern __typeof(gomp_loop_ull_doacross_dynamic_start) GOMP_loop_ull_doacross_dynamic_start
	__attribute__((alias ("gomp_loop_ull_doacross_dynamic_start")));
extern __typeof(gomp_loop_ull_doacross_guided_start) GOMP_loop_ull_doacross_guided_start
	__attribute__((alias ("gomp_loop_ull_doacross_guided_start")));

extern __typeof(gomp_loop_ull_static_next) GOMP_loop_ull_static_next
	__attribute__((alias ("gomp_loop_ull_static_next")));
extern __typeof(gomp_loop_ull_dynamic_next) GOMP_loop_ull_dynamic_next
	__attribute__((alias ("gomp_loop_ull_dynamic_next")));
extern __typeof(gomp_loop_ull_guided_next) GOMP_loop_ull_guided_next
	__attribute__((alias ("gomp_loop_ull_guided_next")));
extern __typeof(gomp_loop_ull_dynamic_next) GOMP_loop_ull_nonmonotonic_dynamic_next
	__attribute__((alias ("gomp_loop_ull_dynamic_next")));
extern __typeof(gomp_loop_ull_guided_next) GOMP_loop_ull_nonmonotonic_guided_next
	__attribute__((alias ("gomp_loop_ull_guided_next")));

extern __typeof(gomp_loop_ull_ordered_static_next) GOMP_loop_ull_ordered_static_next
	__attribute__((alias ("gomp_loop_ull_ordered_static_next")));
extern __typeof(gomp_loop_ull_ordered_dynamic_next) GOMP_loop_ull_ordered_dynamic_next
	__attribute__((alias ("gomp_loop_ull_ordered_dynamic_next")));
extern __typeof(gomp_loop_ull_ordered_guided_next) GOMP_loop_ull_ordered_guided_next
	__attribute__((alias ("gomp_loop_ull_ordered_guided_next")));
_Bool
GOMP_loop_ull_static_start (_Bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_dynamic_start (_Bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull chunk_size,
			     gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_guided_start (_Bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_nonmonotonic_dynamic_start (_Bool up, gomp_ull start,
					  gomp_ull end, gomp_ull incr,
					  gomp_ull chunk_size,
					  gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_nonmonotonic_guided_start (_Bool up, gomp_ull start, gomp_ull end,
					 gomp_ull incr, gomp_ull chunk_size,
					 gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_static_start (_Bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_dynamic_start (_Bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull chunk_size,
				     gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_guided_start (_Bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_doacross_static_start (unsigned ncounts, gomp_ull *counts,
				     gomp_ull chunk_size, gomp_ull *istart,
				     gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_doacross_dynamic_start (unsigned ncounts, gomp_ull *counts,
				      gomp_ull chunk_size, gomp_ull *istart,
				      gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_doacross_guided_start (unsigned ncounts, gomp_ull *counts,
				     gomp_ull chunk_size, gomp_ull *istart,
				     gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_static_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_guided_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_nonmonotonic_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_nonmonotonic_guided_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_static_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
}

_Bool
GOMP_loop_ull_ordered_guided_next (gomp_ull *istart, gomp_ull *iend)
{
}
