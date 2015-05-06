#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

extern void *myHeap;

void main(int argc, char *argv[])
{
	//ititializing heap
	InitializeHeap(myHeap);
	/*printf("old heap address = %p\n", myHeap);
	myHeap = MyRealloc(myHeap, 30000);
	printf("new heap address = %p\n", myHeap);*/
	MemoryMap(myHeap);

	int *p1 = (int*)MyMalloc(sizeof(int));
	double *p2 = (double*)MyMalloc(sizeof(double));
	int *p3 = (int*)MyMalloc(50);
	MemoryMap(myHeap);

	MyFree(p1);
	MyFree(p3);
	MemoryMap(myHeap);

	//myHeap = MyRealloc(myHeap, 30000);
	//float *p4 = (float*)MyRealloc(NULL, sizeof(float));
	float *p4 = (float*)MyMalloc(sizeof(float));
	int *p5 = (int*)MyMalloc(200);
	MemoryMap(myHeap);

	system("pause");
}