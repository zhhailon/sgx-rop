#include <string.h>

#include "sgx_trts.h"
#include "../Enclave.h"
#include "Enclave_t.h"

// hailong:
void ecall_memcpy_in(const char *mem, size_t len)
{
    char buf[10];
    memcpy(buf, mem, len);
    for(int i = 0; i < len; ++i)
    {
        printf("[%3d] %p: 0x%02hhx\n", i, &buf[i], buf[i]);
    }

}

