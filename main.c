#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "minheap.h"
#include "heapnode.h"
#include "huffman.h"


int main() {

    srand(time(NULL));
    int n = 1 + rand() % 256;
    BYTE *binStr = randBinArray(n);

    printf("s    = %s\nn(s) = %d\nb(s) = %d\n\n", binStr, n, CEIL_BY_8(n));

    BYTE *bytes = toBytes(binStr, n);
    printArray(bytes, CEIL_BY_8(n));
    printf("\n\n");

    printf("LOG2(x) TEST\n");
    unsigned test[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 16, 32, 64, 127, 128};
    for(int i=0; i < 14; i++)
        printf("n = %03u -> log2(n) = %u\n", test[i], lg2(test[i]));

    HeapNode_t *n1 = newHeapNode('C', 100);
    HeapNode_t *n2 = newHeapNode('B', 50);
    HeapNode_t *n3 = newHeapNode('A', 2);
    MinHeap_t *heap = newMinHeap(3);

    insertHeapNode(heap, n1);
    insertHeapNode(heap, n2);
    insertHeapNode(heap, n3);

    printMinHeap(heap);
    extractMin(heap);
    printMinHeap(heap);

    return EXIT_SUCCESS;
}
