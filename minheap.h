#ifndef HEAP_H
#define HEAP_H

#include "heapnode.h"

typedef struct MinHeap {
    unsigned capacity;
    unsigned size;
    HeapNode_t **nodes;
} MinHeap_t;

MinHeap_t *newMinHeap(unsigned capacity);
MinHeap_t *buildMinHeap(char *chars, unsigned *counts, unsigned n);
void insertHeapNode(MinHeap_t *heap, HeapNode_t *node);
HeapNode_t *extractMin(MinHeap_t *heap);
void printMinHeap(MinHeap_t *heap);

#endif