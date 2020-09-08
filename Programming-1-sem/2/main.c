#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	float a, z1, z2, pi = 3.14159;
	scanf("%f", &a);
	z1 = pow(cos(3 * pi / 8 - a / 4), 2) - pow(cos(11 * pi / 8 + a / 4), 2);
	z2 = sqrt(2) / 2 * sin(a / 2);
	printf("%f %f", z1, z2);
	return 0;
}
