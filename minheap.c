#include <stdlib.h>
#include <stdio.h>
#include "heapnode.h"
#include "minheap.h"


MinHeap_t *createMinHeap(unsigned capacity) {

    MinHeap_t *heap = (MinHeap_t*) malloc(sizeof(MinHeap_t));
    if(heap != NULL) {
        heap->size = 0;
        heap->capacity = capacity;
        heap->array = (HeapNode_t**) malloc(heap->capacity * sizeof(HeapNode_t*));
    }

    return heap;
}

void minHeapify(MinHeap_t *heap, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->array[left]->count < heap->array[smallest]->count)
        smallest = left;
    if(right < heap->size && heap->array[right]->count < heap->array[smallest]->count)
        smallest = right;

    if(smallest != i) {
        swapHeapNodes(&heap->array[smallest], &heap->array[i]);
        minHeapify(heap, smallest);
    }
}

int isLeaf(HeapNode_t *node) {

    return (!(node->left) && !(node->right));
}

HeapNode_t *extractMin(MinHeap_t *heap) {

    HeapNode_t *node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];

    heap->size--;
    minHeapify(heap, 0);
}

void insertHeapNode(MinHeap_t *heap, HeapNode_t *node) {

    int i = heap->size;
    heap->size++;

    while((i > 0) && (node->count < heap->array[(i - 1) / 2]->count)) {
        heap->array[i] = heap->array[(i - 1)/ 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = node;
}

void printMinHeap(MinHeap_t *heap) {

    printf("size     -> %d\n", heap->size);
    printf("capacity -> %d\n\n", heap->capacity);
    for(int i=0; i < heap->size; i++)
        printHeapNode(heap->array[i]);
}
