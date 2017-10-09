#include "../App.h"
#include "Enclave_u.h"

// hailong:
void ecall_mem_functions(void)
{
    char buf[20];
    for(int i = 0; i < 20; i++)
    {
        buf[i] = i;
    }
    ecall_memcpy_in(global_eid, buf, 20);
}
