/****************************************************************************
 *   PROJECT: Maintain a heap map for heap debugging, 1 bit per 32-bit word
 *            The space overhead is a maximum of 1/32 of the address space.
 *   FILE:    sqHeapMap.c
 *   CONTENT: 
 *
 *   AUTHOR:  Eliot Miranda
 *   ADDRESS: 
 *   EMAIL:   eliot.miranda@gmail.com
 *
 *   NOTES: The idea is to check for heap pointer integrity.  We scan the heap
 *          setting a bit in the map for each object's base header.  We then
 *          scan the heap checking that each pointer points to a base header by
 *          checking for a 1 in the heap map.
 *
 *          We can also check for leaks by scanning a third time and clearing
 *          the header bit.  Any remaining set bits indicate an unreferenced
 *          object that should have been collected.
 *
 ****************************************************************************/

#include "sqMemoryAccess.h" 

#include <stdlib.h>

#define ulong unsigned long
#define uchar unsigned char

#if SQ_IMAGE32
/*
 * 32-bit address space = 2^32 bytes = 2^30 words.  If we have 256 root pages
 * then each page needs to cover 2^30 / 256 words = 4 megawords.  Each 8-bit
 * byte in the leak map covers 8 words.  So each page needs to be 4M / 8 bytes
 * = 512k bytes per page.
 */
 
#define NUMPAGES 256

static uchar *mapPages[256] = { 0, };

#define PAGESIZE (512*1024)
#define PAGESHIFT 24
#define PAGEMASK 0xFFFFFF
#define LOGWORDSIZE 2
#define LOGBITSPERBYTE 3
#define PAGEINDEX(a) ((a) >> PAGESHIFT)
#define BYTEINDEX(a) (((a) & PAGEMASK) >> (LOGWORDSIZE + LOGBITSPERBYTE))
#define BITINDEX(a) (((a) >> LOGWORDSIZE) & ((1<<LOGBITSPERBYTE)-1))

/*
 * Answer non-zero if the heapMap is set at wordPointer, 0 otherwise
 */
int
heapMapAtWord(void *wordPointer)
{
	ulong address = (ulong)wordPointer;
	uchar *page = mapPages[PAGEINDEX(address)];
	if ((address & ((1<<LOGWORDSIZE)-1)))
		error("misaligned word");
	return page
		? page[BYTEINDEX(address)] & (1 << BITINDEX(address))
		: 0;
}

/*
 * Set the value in the map at wordPointer to bit.
 */
void
heapMapAtWordPut(void *wordPointer, int bit)
{
	ulong address = (ulong)wordPointer;
	uchar *page = mapPages[PAGEINDEX(address)];
	if ((address & ((1<<LOGWORDSIZE)-1)))
		error("misaligned word");
	if (!page) {
		if (!(page = malloc(PAGESIZE))) {
			perror("malloc");
			exit(1);
		}
		mapPages[PAGEINDEX(address)] = page;
		memset(page,0,PAGESIZE);
	}
	if (bit)
		page[BYTEINDEX(address)] |= 1 << BITINDEX(address);
	else
		page[BYTEINDEX(address)] &= (uchar)-1 ^ (1 << BITINDEX(address));
}

/*
 * Clear the heap map to zero.
 */
void
clearHeapMap(void)
{
	int i;

	for (i = 0; i < NUMPAGES; i++)
		if (mapPages[i])
			memset(mapPages[i],0,PAGESIZE);
}
#else
# error 64-bit verison not yet implemented (hint: you need another level of indirection to make the table small enough)
#endif
