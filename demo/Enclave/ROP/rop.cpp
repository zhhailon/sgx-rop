extern "C" {
void foo() {}

void heap_stack_push() {
	foo();
}

void heap_stack_pop() {
	foo();
}
}