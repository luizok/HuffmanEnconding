#include <stdlib.h>
#include <stdio.h>
#include "heapnode.h"

HeapNode_t *newHeapNode(char data, unsigned count) {

    HeapNode_t *node = (HeapNode_t*) malloc(sizeof(HeapNode_t));
    if(node != NULL) {
        node->left = NULL;
        node->right = NULL;
        node->data = data;
        node->count = count;
    }

    return node;
}

void swapHeapNodes(HeapNode_t **a, HeapNode_t **b) {

    HeapNode_t *aux = *a;
    *a = *b;
    *b = aux;
}

void printHeapNode(HeapNode_t *node) {

    printf("data  -> 0x%02x (%c)\n", node->data, node->data);
    printf("count -> %02d\n", node->count);
    printf("left  -> %p\n", node->left);
    printf("right -> %p\n\n", node->right);
}
