#include <stdio.h>

int main(void){

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    long long temp1 = 0;
    long long temp2 = 0;
    long long temp3 = 0;
    //long long temp4 = 0;

    asm volatile("mov x17, #1");
    asm volatile("mov x19, #2");
    asm volatile("mov %0, x17":"=r"(a));
    asm volatile("mov %0, x19":"=r"(b));

    
    //printf("before stack a = %d, b = %d\n",a,b);
    asm volatile("stp x17, x19, [sp, #40]");
    //printf("temp1 sp + #40 %lld\n",temp2);
    //printf("temp2 sp + #48 %lld\n",temp2);
    //printf("temp3 sp + #56 %lld\n",temp3);

    asm volatile("mov x17, #3");
    asm volatile("mov x19, #4");
    asm volatile("mov %0, x17":"=r"(c));
    asm volatile("mov %0, x19":"=r"(d));

    //printf("after add a = %d, b = %d\n",c,d);

    asm volatile("ldp x17, x19, [sp, #40]");

    asm volatile("mov %0, x17":"=r"(e));
    asm volatile("mov %0, x19":"=r"(f));
    printf("restore a = %d, b = %d, c = %d, d = %d, e = %d, f = %d\n",a,b,c,d,e,f);

    return 0;
}

// aarch64-linux-gnu-gcc -o test ./test_inline.c
// aarch64-linux-gnu-objdump -d test2.out >t