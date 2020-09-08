#include "header.h"

int main(int argc, char *argv[]) {
	struct pentagon my_fig;
	my_fig = cons();
	printf("%f", perimetr(my_fig));
	return 0;
}
