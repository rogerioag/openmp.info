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

/* This file handles the SECTIONS construct.  */



/* Initialize the given work share construct from the given arguments.  */

static inline void
gomp_sections_init (struct gomp_work_share *ws, unsigned count)
{
}

/* This routine is called when first encountering a sections construct
   that is not bound directly to a parallel construct.  The first thread 
   that arrives will create the work-share construct; subsequent threads
   will see the construct exists and allocate work from it.

   COUNT is the number of sections in this construct.

   Returns the 1-based section number for this thread to perform, or 0 if
   all work was assigned to other threads prior to this thread's arrival.  */

unsigned
GOMP_sections_start (unsigned count)
{
}

/* This routine is called when the thread completes processing of the
   section currently assigned to it.  If the work-share construct is
   bound directly to a parallel construct, then the construct may have
   been set up before the parallel.  In which case, this may be the
   first iteration for the thread.

   Returns the 1-based section number for this thread to perform, or 0 if
   all work was assigned to other threads prior to this thread's arrival.  */

unsigned
GOMP_sections_next (void)
{
}

/* This routine pre-initializes a work-share construct to avoid one
   synchronization once we get into the loop.  */

void
GOMP_parallel_sections_start (void (*fn) (void *), void *data,
			      unsigned num_threads, unsigned count)
{
}


void
GOMP_parallel_sections (void (*fn) (void *), void *data,
			unsigned num_threads, unsigned count, unsigned flags)
{
}

/* The GOMP_section_end* routines are called after the thread is told
   that all sections are complete.  The first two versions synchronize
   all threads; the nowait version does not.  */

void
GOMP_sections_end (void)
{
}

_Bool
GOMP_sections_end_cancel (void)
{
}

void
GOMP_sections_end_nowait (void)
{
}
