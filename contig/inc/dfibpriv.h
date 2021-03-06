/*
 * inc/dfibpriv.h
 *
 * This file is part of SOAPdenovo.
 *
 */

/*
 * Copyright 1997, 1999-2003 John-Mark Gurney.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *  $Id: dfibpriv.h,v 1.8 2007/10/09 09:56:46 zerbino Exp $
 *
 */

#ifndef _DFIBPRIV_H_
#define _DFIBPRIV_H_

//#include "globals.h"
#include "def2.h"

/*
 * specific node operations
 */

static DFibHeapNode * dfhe_newelem ( DFibHeap * );
static void dfhe_insertafter ( DFibHeapNode * a, DFibHeapNode * b );
static inline void dfhe_insertbefore ( DFibHeapNode * a, DFibHeapNode * b );
static DFibHeapNode * dfhe_remove ( DFibHeapNode * a );

/*
 * global heap operations
 */
struct dfibheap
{
	MEM_MANAGER * nodeMemory;
	IDnum dfh_n;
	IDnum dfh_Dl;
	DFibHeapNode ** dfh_cons;
	DFibHeapNode * dfh_min;
	DFibHeapNode * dfh_root;
};

static void dfh_insertrootlist ( DFibHeap *, DFibHeapNode * );
static void dfh_removerootlist ( DFibHeap *, DFibHeapNode * );
static void dfh_consolidate ( DFibHeap * );
static void dfh_heaplink ( DFibHeap * h, DFibHeapNode * y, DFibHeapNode * x );
static void dfh_cut ( DFibHeap *, DFibHeapNode *, DFibHeapNode * );
static void dfh_cascading_cut ( DFibHeap *, DFibHeapNode * );
static DFibHeapNode * dfh_extractminel ( DFibHeap * );
static void dfh_checkcons ( DFibHeap * h );
static int dfh_compare ( DFibHeap * h, DFibHeapNode * a, DFibHeapNode * b );
static int dfh_comparedata ( DFibHeap * h, Time key,
                             unsigned int data, DFibHeapNode * b );
static void dfh_insertel ( DFibHeap * h, DFibHeapNode * x );


/*
 * general functions
 */
static inline IDnum ceillog2 ( IDnum a );

#endif              /* _FIBPRIV_H_ */
