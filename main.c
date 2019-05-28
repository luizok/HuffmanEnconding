#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CEIL_BY_8(n) n / 8 + (n % 8 ? 1 : 0)

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
    printf("\n");

    return EXIT_SUCCESS;
}