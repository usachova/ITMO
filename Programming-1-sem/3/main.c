#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b;
	scanf("%o", &a);
	printf("%d\n", a);
	printf("%o %o\n", a, a >> 3);
	printf("%o %o\n", a, ~a);
	scanf("%o", &b);
	printf("%o\n", a|b);	
	return 0;
}
