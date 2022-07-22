#include <stdio.h>

int main(void){
    int a = 1;
    int b = 2;

    asm volatile("add x0, %0, #123"
        :
        : "r"(a)
    );

    asm volatile("mov %0, x0"
        :"=r"(b)
        :
        :
    );

    printf("%d \n",b);

    return 0;
}

// aarch64-linux-gnu-gcc -o test ./test_inline.c