#include <string.h>

#include "sgx_trts.h"
#include "../Enclave.h"
#include "Enclave_t.h"
#include <inttypes.h>

void foo(int, int, int, int);

// hailong:
void ecall_memcpy_in(const uint64_t *mem, size_t len)
{
    uint64_t buf[1];
    // memcpy(buf, mem, len * sizeof(uint64_t));
    // for(int i = 0; i < len; ++i)
    // {
    //     printf("[%3d] %p: 0x%" PRIx64 "\n", i, &buf[i], buf[i]);
    // }

	asm (
		"push %rbx;"
		"pop %rbx;"
	);

    printf("ecall_memcpy_in\n");

    foo(1,2,3,4);
}
