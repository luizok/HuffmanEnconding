#include <stdlib.h>
#include <stdio.h>
#include "minheap.h"


MinHeap_t *newMinHeap(unsigned capacity);
void insertHeapNode(MinHeap_t *heap, HeapNode_t *node);
MinHeap_t *buildMinHeap(char *chars, unsigned *counts, unsigned n);
void minHeapify(MinHeap_t *heap, unsigned i);
HeapNode_t *extractMin(MinHeap_t *heap);
void printN(HeapNode_t *node);
void printPadding(unsigned depth);
void _printHeap(MinHeap_t *heap, unsigned idx, unsigned depth);
void printMinHeap(MinHeap_t *heap);


MinHeap_t *newMinHeap(unsigned capacity) {

    MinHeap_t *heap = (MinHeap_t*) malloc(sizeof(MinHeap_t));

    if(heap != NULL) {
        heap->capacity = capacity;
        heap->size = 0;
        heap->nodes = (HeapNode_t**) malloc(heap->capacity * sizeof(HeapNode_t*));
    }

    return heap;
}

void insertHeapNode(MinHeap_t *heap, HeapNode_t *node) {

    int i = heap->size;
    heap->size++;

    while((i > 0) && (node->count < heap->nodes[(i - 1) / 2]->count)) {
        heap->nodes[i] = heap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->nodes[i] = node;
}

MinHeap_t *buildMinHeap(char *chars, unsigned *counts, unsigned n) {

    MinHeap_t *heap = newMinHeap(n);
    HeapNode_t *node = NULL;

    for(int i=0; i < n; i++) {
        node = newHeapNode(chars[i], counts[i]);
        insertHeapNode(heap, node);
    }

    return heap;
}

void minHeapify(MinHeap_t *heap, unsigned i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->nodes[left]->count < heap->nodes[i]->count)
        smallest = left;
    if(right < heap->size && heap->nodes[right]->count < heap->nodes[i]->count)
        smallest = right; 

    if(smallest != i) {
        swapHeapNodes(&heap->nodes[i], &heap->nodes[smallest]);
        minHeapify(heap, smallest);
    }
}

HeapNode_t *extractMin(MinHeap_t *heap) {

    HeapNode_t *min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];

    heap->size--;
    minHeapify(heap, 0);

    return min;
}

void printN(HeapNode_t *node) {
    printf("[%c | %2u]\n", node->data, node->count);
}

void printPadding(unsigned depth) {
    for(int k=0; k < depth; k++)
        printf("\t");
}

void _printHeap(MinHeap_t *heap, unsigned idx, unsigned depth) {

    if(idx < heap->size) {
        printPadding(depth);
        printN(heap->nodes[idx]);

        _printHeap(heap, 2 * idx + 1, depth + 1);
        _printHeap(heap, 2 * idx + 2, depth + 1);
    }
}

void printMinHeap(MinHeap_t *heap) {

    if(heap->size == 0)
        printf("Heap is empty\n");

    _printHeap(heap, 0, 0);
    printf("\n");
}