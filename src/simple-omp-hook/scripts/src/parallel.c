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

/* This file handles the (bare) PARALLEL construct.  */



/* Determine the number of threads to be launched for a PARALLEL construct.
   This algorithm is explicitly described in OpenMP 3.0 section 2.4.1.
   SPECIFIED is a combination of the NUM_THREADS clause and the IF clause.
   If the IF clause is false, SPECIFIED is forced to 1.  When NUM_THREADS
   is not present, SPECIFIED is 0.  */

unsigned
gomp_resolve_num_threads (unsigned specified, unsigned count)
{
}

void
GOMP_parallel_start (void (*fn) (void *), void *data, unsigned num_threads)
{
}

void
GOMP_parallel_end (void)
{
}

void
GOMP_parallel (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags)
{
}

_Bool
GOMP_cancellation_point (int which)
{
}

_Bool
GOMP_cancel (int which, _Bool do_cancel)
{
}

/* The public OpenMP API for thread and team related inquiries.  */

int
omp_get_num_threads (void)
{
}

int
omp_get_thread_num (void)
{
}

/* This wasn't right for OpenMP 2.5.  Active region used to be non-zero
   when the IF clause doesn't evaluate to false, starting with OpenMP 3.0
   it is non-zero with more than one thread in the team.  */

int
omp_in_parallel (void)
{
}

int
omp_get_level (void)
{
}

int
omp_get_ancestor_thread_num (int level)
{
}

int
omp_get_team_size (int level)
{
}

int
omp_get_active_level (void)
{
}

