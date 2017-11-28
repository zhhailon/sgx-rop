extern "C" {

char *shadowstack = NULL;
char *shadowrsp = NULL;

void checkheapexistence()
{
	if(shadowstack == NULL)
	{
		shadowstack = (char*)malloc(1000);
		shadowrsp = shadowstack;
	}
}

void checkrsp()
{

}




void heap_stack_push() {
	checkheapexistence();



}

void heap_stack_pop() {
	checkheapexistence();
	checkrsp();




}

}




