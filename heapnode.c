#include <stdio.h>
#include <stdlib.h>
#include "heapnode.h"


HeapNode_t *newHeapNode(unsigned char data, unsigned count);
void swapHeapNodes(HeapNode_t **a, HeapNode_t **b);
void printHeapNode(HeapNode_t *node);


HeapNode_t *newHeapNode(unsigned char data, unsigned count) {

    HeapNode_t *node = (HeapNode_t*) malloc(sizeof(HeapNode_t));

    if(node != NULL) {
        node->data = data;
        node->count = count;
        node->nBits = 0;
        node->code = 0;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void swapHeapNodes(HeapNode_t **a, HeapNode_t **b) {

    HeapNode_t *aux = *a;
    *a = *b;
    *b = aux;
}

void printHeapNode(HeapNode_t *node) {

    printf("node->data  = %c (0x%02x)\n", node->data, node->data);
    printf("node->count = %u\n", node->count);
    printf("\n");
}