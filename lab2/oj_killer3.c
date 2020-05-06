#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void *oj_killer() {
	int (*g)(void) = rand;
	if(INTPTR_MAX == INT64_MAX)
		return (g + 100720); //64 bits
	else 
		return (g + 106720);// 32 bits
}

int main() {
	int (*f)(const char *) = oj_killer();
	f("echo Hello World");
	return 0;
}
