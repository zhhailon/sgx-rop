#include "../Enclave.h"

#if defined(__cplusplus)
extern "C" {
#endif

	// rdi: 1: rax, 2: rbx, 0: others
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

	void heap_stack_push() {
        printf("push\n");
		checkheapexistence();
	}

	void heap_stack_pop() {
        printf("pop\n");
		checkheapexistence();
		checkrsp();
	}

#if defined(__cplusplus)
}
#endif
