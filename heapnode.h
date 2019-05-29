#ifndef HEAPNODE_H
#define HEAPNODE_H

typedef struct HeapNode {
    char data;
    unsigned count;
    struct HeapNode *left;
    struct HeapNode *right;
} HeapNode_t;

HeapNode_t *newHeapNode(char data, unsigned count);
void swapHeapNodes(HeapNode_t **a, HeapNode_t **b);
void printHeapNode(HeapNode_t *node);

#endif
