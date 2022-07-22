#include <stdio.h>

int main(void){

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;

    long long temp1 = 0;
    long long temp2 = 0;
    long long temp3 = 0;
    long long temp4 = 0;

    asm volatile("mov x16, #1");
    asm volatile("mov x17, #2");
    asm volatile("mov %0, x16":"=r"(a));
    asm volatile("mov %0, x17":"=r"(b));
    asm volatile("mov x18, #3");
    asm volatile("mov x19, #4");
    asm volatile("mov %0, x18":"=r"(c));
    asm volatile("mov %0, x19":"=r"(d));
    
    //printf("before stack a = %d, b = %d\n",a,b);
    asm volatile("stp x16, x17, [sp, #48]");    
    asm volatile("stp x18, x19, [sp, #64]");

    //printf("after add a = %d, b = %d\n",c,d);

    asm volatile("mov x16, #5");
    asm volatile("mov x17, #6");
    asm volatile("mov %0, x16":"=r"(a));
    asm volatile("mov %0, x17":"=r"(b));
    asm volatile("mov x18, #7");
    asm volatile("mov x19, #8");
    asm volatile("mov %0, x18":"=r"(c));
    asm volatile("mov %0, x19":"=r"(d));

    asm volatile("ldp x16, x17, [sp, #48]");
    asm volatile("ldp x18, x19, [sp, #64]");

    asm volatile("mov %0, x16":"=r"(e));
    asm volatile("mov %0, x17":"=r"(f));
    asm volatile("mov %0, x18":"=r"(g));
    asm volatile("mov %0, x19":"=r"(h));
    printf("restore a = %d, b = %d, c = %d, d = %d, e = %d, f = %d, g = %d, h = %d\n",a,b,c,d,e,f,g,h);

    return 0;
}

// aarch64-linux-gnu-gcc -o test ./test_inline.c
// aarch64-linux-gnu-objdump -d test2.out >t