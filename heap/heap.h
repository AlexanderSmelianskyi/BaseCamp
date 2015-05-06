#ifndef HEAP_H
#define HEAP_H

//@brief This function creates my heap
//@param size of heap in bytes
//@return pointer to heap
void *CreateHeap(size_t);

//@brief This function converts virtual address to real address
//@param virtual address to convert
//@return real address
void *ConvertVirtToReal(size_t);

//@brief This function converts real address to virtual address
//@param real address to convert
//@return virtual address
size_t ConvertRealToVirt(void *);

//@brief This function initializes heap, creates headers with service information
//@param pointer to heap to initialize
//@return void
void InitializeHeap(void *);

//@brief This function returns pointer to free memory region if there are one
//@param size of needed memory block
//@return pointer to free memory
void *MyMalloc(size_t);

//@brief This function returns pointer to reallocated memory
//@param pointer to old memory block
//@param size of needed memory block
//@return pointer to new block of memory
void *MyRealloc(void *, size_t);

//@brief This function frees memory if pointer points to heap memory and does nothing otherwise
//@param pointer to memory we want to make free
//@return void
void MyFree(void *);

//@brief This function shows map of memory.
//@param pointer to heap
//@return void
void MemoryMap(void *);

#endif