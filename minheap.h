#ifndef MINHEAP_H
#define MINHEAP_H

#include "heapnode.h"

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    HeapNode_t **array;
} MinHeap_t;

MinHeap_t *createMinHeap(unsigned capacity);
void insertHeapNode(MinHeap_t *heap, HeapNode_t *node);
HeapNode_t* extractMin(MinHeap_t* heap);
int isLeaf(HeapNode_t *node);

void printMinHeap(MinHeap_t *heap);


#endif
