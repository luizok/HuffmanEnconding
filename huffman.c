#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "minheap.h"
#include "huffman.h"


MinHeap_t *buildHuffmanTree(MinHeap_t *heap);
void updateCodes(HeapNode_t *root, unsigned bits, unsigned nBits);
unsigned lg2(unsigned n);
BYTE* randBinArray(unsigned n);
BYTE* toBytes(BYTE *_nums, unsigned n);
void printArray(BYTE *arr, unsigned n);
int isLeaf(HeapNode_t *node);
void printHuffmanTree(MinHeap_t *tree);


MinHeap_t *buildHuffmanTree(MinHeap_t *heap) {

    MinHeap_t *tree = newMinHeap(heap->capacity);

    HeapNode_t *node = NULL;
    for(int i=0; i < heap->size; i++) {
        node = newHeapNode(heap->nodes[i]->data, heap->nodes[i]->count);
        insertHeapNode(tree, node);
    }

    HeapNode_t *left = NULL;
    HeapNode_t *right = NULL;
    while(tree->size > 1) {
        left = extractMin(tree);
        right = extractMin(tree);

        node = newHeapNode('\0', left->count + right->count);
        node->left = left;
        node->right = right;

        insertHeapNode(tree, node);
    }

    updateCodes(tree->nodes[0], 0, 0);

    return tree;
}

void updateCodes(HeapNode_t *root, unsigned bits, unsigned nBits) {

    if(root) {
        if(isLeaf(root)) {
            root->code = bits;
            root->nBits = nBits;
        }
        updateCodes(root->left, (bits << 1) | 0, nBits + 1);
        updateCodes(root->right, (bits << 1) | 1, nBits + 1);
    }
}


unsigned lg2(unsigned n) {

    if(n == 0) return UINT_MAX;

    unsigned i = 0;
    while(n >>= 1) i++;

    return i;
}

BYTE* randBinArray(unsigned n) {

    BYTE *binStr = malloc(n * sizeof(BYTE));
    for(int i=0; i < n; i++)
        sprintf(&binStr[i], "%d", rand() % 2);

    return binStr;
}

BYTE* toBytes(BYTE *_nums, unsigned n) {
    BYTE *bytes = calloc(CEIL_BY_8(n), sizeof(BYTE));
    if(bytes != NULL) {
        for(int b=0; b < n; b++) {
            bytes[b / 8] <<= 1;
            bytes[b / 8] |= _nums[b] == '1' ? 1 : 0;
        }

        bytes[n / 8] <<= 8 - (n % 8);

        return  bytes;
    }

    return NULL;
}

void printArray(BYTE *arr, unsigned n) {

    for(int i=0; i < n; i++) {
        if(i % 16 == 0 && i != 0)
            printf("\n");
        printf("0x%02X  ", arr[i]);
    }
}

int isLeaf(HeapNode_t *node) {

    return node->left == NULL && node->right == NULL;
}

void printR(HeapNode_t *node) {

    if(isLeaf(node))
        printf("\033[1;31m");

    printf("[%c | %2u] ", node->data, node->count);
    if(isLeaf(node))
        for(int i=node->nBits-1; i >= 0; i--) {
            printf("%d", (node->code >> i) & 1);
        }
    printf("\033[m\n");
}

void printPaddingH(unsigned depth) {
    for(int k=0; k < depth; k++)
        printf("\t");
}

void _printHuffmanTree(HeapNode_t *root, unsigned depth) {

    if(root) {
        printPaddingH(depth);
        printR(root);

        _printHuffmanTree(root->left, depth + 1);
        _printHuffmanTree(root->right, depth + 1);
    }
}

void printHuffmanTree(MinHeap_t *tree) {

    if(tree->size == 0)
        printf("Heap is empty\n");

    _printHuffmanTree(tree->nodes[0], 0);
    printf("\n");
}