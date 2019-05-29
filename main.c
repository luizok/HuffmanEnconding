#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include "heapnode.h"
#include <time.h>
#include <limits.h>
#define CEIL_BY_8(n) n / 8 + (n % 8 ? 1 : 0)


unsigned lg2(unsigned n) {

    if(n == 0) return UINT_MAX;

    unsigned i = 0;
    while(n >>= 1) i++;

    return i;
}


typedef unsigned char BYTE;

BYTE* randBinArray(int n) {

    BYTE *binStr = malloc(n * sizeof(BYTE));
    for(int i=0; i < n; i++)
        sprintf(&binStr[i], "%d", rand() % 2);

    return binStr;
}

BYTE* toBytes(BYTE *_nums, int n) {
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

void printArray(BYTE *arr, int n) {

    for(int i=0; i < n; i++) {
        if(i % 16 == 0 && i != 0)
            printf("\n");
        printf("0x%02X  ", arr[i]);
    }
}

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

//    HeapNode_t *n1 = newHeapNode('C', 100);
//    HeapNode_t *n2 = newHeapNode('B', 50);
//    HeapNode_t *n3 = newHeapNode('A', 2);
//    MinHeap_t *heap = createMinHeap(3);
//
//    insertHeapNode(heap, n1);
//    insertHeapNode(heap, n2);
//    insertHeapNode(heap, n3);
//
//    printMinHeap(heap);
//    extractMin(heap);
//    printMinHeap(heap);

    return EXIT_SUCCESS;
}
