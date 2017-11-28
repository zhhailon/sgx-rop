#include <string.h>

#include "sgx_trts.h"
#include "../Enclave.h"
#include "Enclave_t.h"
#include <inttypes.h>

// void heap_stack_push();
// void heap_stack_pop();

// hailong:
void ecall_memcpy_in(const uint64_t *mem, size_t len)
{
    uint64_t buf[1];
    memcpy(buf, mem, len * sizeof(uint64_t));
    for(int i = 0; i < len; ++i)
    {
        printf("[%3d] %p: 0x%" PRIx64 "\n", i, &buf[i], buf[i]);
    }
    // heap_stack_push();
    // heap_stack_pop();
}
