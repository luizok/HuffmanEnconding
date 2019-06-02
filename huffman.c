#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "huffman.h"


unsigned lg2(unsigned n);
BYTE* randBinArray(unsigned n);
BYTE* toBytes(BYTE *_nums, unsigned n);
void printArray(BYTE *arr, unsigned n);


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