#include "../Enclave.h"
#include "Enclave_t.h"  /* print_string */

void foo(int a, int b, int c, int d) {
    char buf[100] = "hello\n";
    ocall_print_string(buf);

	a = 1;
	b = 3;
	d = a * b + a;
	c = d * b + b - a;
    printf("%d\n", c);

	if (a)
	{
		c = a;
		return;
	} else {
		c = b;
		return;
	}
}