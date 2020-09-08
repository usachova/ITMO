#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b;
	scanf("%d", &a);
	(a >= 23 && a <= 32) ? printf("in range\n") : printf("not in range\n");
	scanf("%o", &b);
	printf("%d\n", 1 & (b >> 7));
	//printf("%d\n", ((1 << 7) & b) >> 7);
	return 0;
}
