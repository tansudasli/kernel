#include <stdio.h>

int main(int argc, char **argv) {
    int num = 5;           //assign number or *pointer
    int *numPtr = &num;    //waits a pointer of integer == address
    int num2 = *numPtr;    //*pointer = indirection of pointer

    printf("num=%d\n", num);
    printf("numPtr=%x\n", numPtr);
    printf("address of num=%x\n", &num);

    return 0;
}