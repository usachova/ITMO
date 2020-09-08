#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int arr[4];
	arr[0] = 50;
	arr[1] = 40;
	arr[2] = 30;
	arr[3] = 20;
	int *ptr;
	ptr = &arr[0];
	for (int i = 0; i < 4; i++) {
		printf("%d |", i);
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("---", i);
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("%d|", *(ptr + i));
	}
	printf("\n\n");
	ptr = (int*)malloc(4 * sizeof(int));
	*ptr = 50;
	*(ptr + 1) = 40;
	*(ptr + 2) = 30;
	*(ptr + 3) = 20;
	for (int i = 0; i < 4; i++) {
		printf("%d |", i);
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("---", i);
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("%d|", *(ptr + i));
	}
	free(ptr);
	return 0;
}
