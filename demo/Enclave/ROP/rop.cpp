#include "../Enclave.h"
#include <stdint.h>

void foo() {
    uint64_t i = 2;
    asm("movq %0, %%rbx" :: "r"(i));
    register int myrbx asm("rbx");
    printf("rbx = 0x%x\n", myrbx);
}

#if defined(__cplusplus)
extern "C" {
#endif

    // rdi: 1: rax, 2: rbx, 0: others
    int which_reg = 0;
    char *shadowstack = 0;
    char *shadowrsp = 0;

    void checkheapexistence()
    {
        if(shadowstack == 0)
        {
            shadowstack = (char*)malloc(1000);
            shadowrsp = shadowstack;
        }
    }

    void checkrsp()
    {

    }

    void heap_stack_push(int a) {
        printf("push\n");
        register int myrsp asm("rsp");
        printf("0x%x - 0x%x = 0x%x\n", a, myrsp, a - myrsp);
        checkheapexistence();
    }

    void heap_stack_pop(int a) {
        printf("pop\n");
        register int myrsp asm("rsp");
        printf("0x%x - 0x%x = 0x%x\n", a, myrsp, a - myrsp);
        checkheapexistence();
        checkrsp();
        foo();
    }

#if defined(__cplusplus)
}
#endif
