#include <stdio.h>
#include <stdlib.h>
void *oj_killer() {
	int (*g)(void) = rand;
#ifdef __x86_64__	
	return (g + 100720); //64 bits
#endif
		return (g + 106720);// 32 bits
}

int main() {
	int (*f)(const char *) = oj_killer();
	f("echo Hello World");
	return 0;
}
