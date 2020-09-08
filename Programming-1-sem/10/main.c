#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
	float x;
	float y;
};

float distance(struct point a, struct point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

float arr[100][100];

void table(int k, struct point ps[]) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i != j) {
				arr[i][j - (j > i) ? 1 : 0] = distance(ps[i], ps[j]);
				printf("%.2f ", arr[i][j - (j > i) ? 1 : 0]);
			}
			printf("\n");
		}
	}
}

int sum(int x) {
	int res = 0;
	if (x == 0) return res;
	res = x % 10 + sum(x / 10);
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	struct point mas[n];
	for (int i = 0; i < n; i++) {
		scanf("%f%f", &mas[i].x, &mas[i].y);
	}
	table(n, mas);
	
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}
