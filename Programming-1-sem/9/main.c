#include <stdio.h>
#include <stdlib.h>

int is_simple(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int free_min = 499;
	int talk_cnt;
	float sub_fee, cost_min;
	scanf("%d %f %f", &talk_cnt, &sub_fee, &cost_min);
	while (cost_min <= sub_fee/free_min) {
		printf("incorrectly entered");
		scanf("%f", &cost_min);
	}
	if (talk_cnt > free_min) printf("%f\n", sub_fee + (talk_cnt - free_min) * cost_min);
	else printf("%f\n", sub_fee);
	
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (is_simple(i) == 1) printf("%d ", i);
	}
	return 0;
}
