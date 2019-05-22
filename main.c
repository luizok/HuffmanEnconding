#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef unsigned char byte;

byte* toBytes(byte *_nums, int n) {
    byte *bytes = calloc(n / 8, sizeof(byte));
    if(bytes != NULL) {
        for(int b=0; b < n; b++) {
            bytes[b / 8] <<= 1;
            bytes[b / 8] |= _nums[b] == '1' ? 1 : 0;
        }

        return  bytes;
    }

    return NULL;
}

void printArray(byte *arr, int n) {

    for(int i=0; i < n; i++) {
        if(i % 16 == 0 && i != 0)
            printf("\n");
        printf("0x%02X  ", arr[i]);
    }
}

int main() {

    byte nums[SIZE] = "11110000";

    printArray(nums, SIZE);
    printf("\n\n");

    byte *bytes = toBytes(nums, SIZE);
    printArray(bytes, SIZE / 8);
    printf("\n");

    return EXIT_SUCCESS;
}