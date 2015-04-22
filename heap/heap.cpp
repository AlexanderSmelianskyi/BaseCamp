#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include "heap.h"

#define FREE 1
#define BUSY 0

//Service info interface
struct ServiceInfo
{
	unsigned short status;
	unsigned short size;
	void *memBlock;
};

void *myHeap = CreateHeap(20480);
void *servInfoStart = NULL;
void *servInfoEnd = NULL;
//size of heap was saved "4 bytes before"
size_t heapSize;

//@brief This function creates my heap
//@param size - size of heap in bytes
//@return pointer to heap
void *CreateHeap(size_t size)
{
	void *heapPtr = malloc(size);
	servInfoStart = malloc(size);
	//if malloc failed
	if (heapPtr == NULL)
		return NULL;

	//first 4 bytes in heap = heap size
	heapSize = size;
	//return pointer to heap which points to next address after size value
	return heapPtr;
}

//@brief This function converts virtual address to real address
//@param virtual address to convert
//@return real address
inline void *ConvertVirtToReal(size_t virtAddr)
{
	return ((char*)myHeap + virtAddr);
}

//@brief This function converts real address to virtual address
//@param real address to convert
//@return virtual address
inline size_t ConvertRealToVirt(void *realAddr)
{
	return ((char*)realAddr - myHeap);
}

//@brief This function initializes heap, creates headers with service information
//@param myHeap - pointer to heap to initialize
//@return void
void InitializeHeap(void *myHeap)
{
	ServiceInfo *si = (ServiceInfo*)servInfoStart;
	si->status = FREE;
	si->size = heapSize;
	si->memBlock = myHeap;

	//end of heap service info
	si += sizeof(ServiceInfo);
	si->status = BUSY;
	si->size = 0;
	si->memBlock = NULL;
	servInfoEnd = si;
}

//@brief This function returns pointer to free memory region if there are one
//@param bytes - size of needed memory region
//@return pointer to free memory
void *MyMalloc(size_t bytes)
{
	ServiceInfo *si = (ServiceInfo*)servInfoStart;
	//size of cutted part
	size_t tSize;
	void *ptrToReturn = NULL;
	while (si->memBlock != NULL)
	{
		if (si->status == FREE && si->size >= bytes)
			break;
		si += sizeof(ServiceInfo);
	}
	//if free block with requested size is finded
	if (si->memBlock != NULL)
	{
		if (bytes < si->size)
		{
			//setting block as BUSY
			tSize = si->size - bytes;
			si->status = BUSY;
			si->size = bytes;
			//saving pointer to return
			ptrToReturn = si->memBlock;

			si = (ServiceInfo*)servInfoEnd;
			si->status = FREE;
			si->size = tSize;
			si->memBlock = (char*)ptrToReturn + bytes;

			//end of heap service info
			si += sizeof(ServiceInfo);
			si->status = BUSY;
			si->size = 0;
			si->memBlock = NULL;

			servInfoEnd = si;

			return ptrToReturn;
		}
		else
			if (bytes == si->size)
			{
				//setting block as BUSY
				tSize = bytes - si->size;
				si->status = BUSY;
				si->size = bytes;
				ptrToReturn = si->memBlock;

				return ptrToReturn;
			}
	}
	return NULL;
}

//@brief This function frees memory if pointer points to heap memory and does nothing otherwise
//@param memoryToFree - pointer to memory we want to make free
//@return void
void MyFree(void *memoryToFree)
{
	ServiceInfo *si = (ServiceInfo*)servInfoStart;

	while (si->memBlock != NULL)
	{
		if (memoryToFree == si->memBlock)
		{
			si->status = FREE;
			return;
		}
		si += sizeof(ServiceInfo);
	}
}

//@brief This function returns pointer to reallocated memory
//@param memToRealloc - pointer to old memory block
//@param bytes -		size of needed memory block
//@return pointer to new block of memory
void *MyRealloc(void *memToRealloc, size_t bytes)
{
	//in case if memToRealloc = NULL realloc works as malloc
	if (memToRealloc == NULL)
	{
		return MyMalloc(bytes);
	}

	void *newBlockPtr = malloc(bytes);
	ServiceInfo *si = (ServiceInfo*)servInfoStart;
	//variable to modify heap size
	ServiceInfo *lastBlock = (ServiceInfo*)servInfoStart;
	if (newBlockPtr != NULL)
	{
		while (si->memBlock != NULL)
		{
			if (si->memBlock > lastBlock->memBlock)
			{
				lastBlock = si;
			}
			si += sizeof(ServiceInfo);
		}
		memcpy(newBlockPtr, memToRealloc, heapSize);
		si = (ServiceInfo*)servInfoStart;
		while (si->memBlock != NULL)
		{
			//new address = begginning of the new heap + shift(block address - old begginning of the heap)
			si->memBlock = (char*)newBlockPtr + ((char*)si->memBlock - (char*)memToRealloc);
			si += sizeof(ServiceInfo);
		}

		//lastBlock points to the last initialized block in heap
		si = (ServiceInfo*)lastBlock;
		//calculating increased size
		si->size += (bytes - heapSize);
		heapSize = bytes;

		return newBlockPtr;
	}
	return NULL;
}

//@brief This function shows map of memory
//@param myHeap - pointer to heap
//@return void
void MemoryMap(void *myHeap)
{
	//table header
	printf("\nVirtual address\tReal address\tStatus\tSize\n");

	ServiceInfo* si = (ServiceInfo*)servInfoStart;
	while (si->memBlock != NULL )
	{
		printf("%d\t\t%p\t%c\t%d\n", ((char*)si->memBlock - myHeap), (char*)si->memBlock, (si->status == FREE) ? 'F' : 'B', si->size);
		si = si + sizeof(ServiceInfo);
	}
}