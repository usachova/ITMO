#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int arr[7] = {90, 76, 54, 23, 56, 12, 48};
	for (int i = 0; i < 7; i++) {
		printf("%d |", i);
	}
	printf("\n");
	for (int i = 0; i < 7; i++) {
		printf("---", i);
	}
	printf("\n");
	for (int i = 0; i < 7; i++) {
		printf("%d|", arr[i]);
	}
	printf("\n\n");
	int arr1[2][2], arr2[2][2];
	arr1[0][0] = 2;
	arr1[0][1] = 5;
	arr1[1][0] = 2;
	arr1[1][1] = 2;
	arr2[0][0] = 1;
	arr2[0][1] = 2;
	arr2[1][0] = 0;
	arr2[1][1] = 1;
	printf("  | 0| 1|\n---------\n");
	for (int i = 0; i < 2; i++) {
		printf("%d |", i);
		for (int j = 0; j < 2; j++) {
			printf(" %d|", arr1[i][0] * arr2[0][j] + arr1[i][1] * arr2[1][j]);
		}
		printf("\n---------\n");
	}
	return 0;
}
