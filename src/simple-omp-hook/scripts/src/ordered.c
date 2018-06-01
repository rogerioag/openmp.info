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

/* This file handles the ORDERED construct.  */



/* This function is called when first allocating an iteration block.  That
   is, the thread is not currently on the queue.  The work-share lock must
   be held on entry.  */

void
gomp_ordered_first (void)
{
}

/* This function is called when completing the last iteration block.  That
   is, there are no more iterations to perform and so the thread should be
   removed from the queue entirely.  Because of the way ORDERED blocks are
   managed, it follows that we currently own access to the ORDERED block,
   and should now pass it on to the next thread.  The work-share lock must
   be held on entry.  */

void
gomp_ordered_last (void)
{
}


/* This function is called when allocating a subsequent allocation block.
   That is, we're done with the current iteration block and we're allocating
   another.  This is the logical combination of a call to gomp_ordered_last
   followed by a call to gomp_ordered_first.  The work-share lock must be
   held on entry. */

void
gomp_ordered_next (void)
{
}


/* This function is called when a statically scheduled loop is first
   being created.  */

void
gomp_ordered_static_init (void)
{
}

/* This function is called when a statically scheduled loop is moving to
   the next allocation block.  Static schedules are not first come first
   served like the others, so we're to move to the numerically next thread,
   not the next thread on a list.  The work-share lock should *not* be held
   on entry.  */

void
gomp_ordered_static_next (void)
{
}

/* This function is called when we need to assert that the thread owns the
   ordered section.  Due to the problem of posted-but-not-waited semaphores,
   this needs to happen before completing a loop iteration.  */

void
gomp_ordered_sync (void)
{
}

/* This function is called by user code when encountering the start of an
   ORDERED block.  We must check to see if the current thread is at the
   head of the queue, and if not, block.  */

extern void GOMP_ordered_start (void)
	__attribute__((alias ("gomp_ordered_sync")));
void
GOMP_ordered_start (void)
{
}

/* This function is called by user code when encountering the end of an
   ORDERED block.  With the current ORDERED implementation there's nothing
   for us to do.

   However, the current implementation has a flaw in that it does not allow
   the next thread into the ORDERED section immediately after the current
   thread exits the ORDERED section in its last iteration.  The existance
   of this function allows the implementation to change.  */

void
GOMP_ordered_end (void)
{
}

/* DOACROSS initialization.  */


void
gomp_doacross_init (unsigned ncounts, long *counts, long chunk_size)
{
}

/* DOACROSS POST operation.  */

void
GOMP_doacross_post (long *counts)
{
}

/* DOACROSS WAIT operation.  */

void
GOMP_doacross_wait (long first, ...)
{
}

typedef unsigned long long gomp_ull;

void
gomp_doacross_ull_init (unsigned ncounts, gomp_ull *counts, gomp_ull chunk_size)
{
}

/* DOACROSS POST operation.  */

void
GOMP_doacross_ull_post (gomp_ull *counts)
{
}

/* DOACROSS WAIT operation.  */

void
GOMP_doacross_ull_wait (gomp_ull first, ...)
{
}
