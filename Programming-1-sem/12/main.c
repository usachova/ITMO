#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *f;
	f = fopen(argv[1], "r");
	char str[100];
	int cnt = 0;
	while (!feof(f)) {
		fscanf(f, "%s", str);
		if (cnt % 2 == 0) printf("%s\n", str);
		cnt++;
	}
	fclose(f);
	return 0;
}
