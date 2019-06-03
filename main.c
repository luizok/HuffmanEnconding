#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "minheap.h"
#include "heapnode.h"
#include "huffman.h"


int main() {

    BYTE bytes[] = "abcdefghijk";
    unsigned counts[] = {13, 256, 12, 15, 27, 89, 156, 46, 86, 48, 9};
    MinHeap_t *heap = buildMinHeap(bytes, counts, 11);

    MinHeap_t *tree = buildHuffmanTree(heap);
    printHuffmanTree(tree);


    return EXIT_SUCCESS;
}
