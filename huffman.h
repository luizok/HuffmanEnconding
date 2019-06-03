#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "minheap.h"

#define CEIL_BY_8(n) n / 8 + (n % 8 ? 1 : 0)


typedef unsigned char BYTE;
MinHeap_t *buildHuffmanTree(MinHeap_t *heap);
unsigned lg2(unsigned n);
BYTE* randBinArray(unsigned n);
BYTE* toBytes(BYTE *_nums, unsigned n);
void printArray(BYTE *arr, unsigned n);
void printHuffmanTree(MinHeap_t *tree);


#endif
