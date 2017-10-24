#include "../App.h"
#include "Enclave_u.h"
#include <cstring>
#include <inttypes.h>
#include <unistd.h>

// hailong:
void ecall_mem_functions(void)
{
    uint64_t buf[30];
    memset(buf, 0xff, 30 * sizeof(uint64_t));
    for (uint64_t i = 0x7ffff5000000;
            i <= 0x7ffff502b000;
            i++) {
        buf[3] = i;
        /* printf("%p buf[ 0]=0x%" PRIx64 "\n", buf, i); */
        for (int j = 4; j < 30; j++) {
            buf[j] = -1;
            /* printf("%p buf[%2d]=0x%" PRIx64 "\n", &buf[j], j, buf[j]); */
        }

        printf("PID=%d\n", getpid());
        printf("Enter a character to enter enclave...\n");
        getchar();

        ecall_memcpy_in(global_eid, buf, 4);
    }
}
