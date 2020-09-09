#include "header.h"

void my_swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}
void my_swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void my_round(double& x) {
	x = (int)x;
}
void my_round(double* x) {
	*x = (int)(*x);
}

void multi(com& x, double& y) {
	x.im *= y;
	x.re *= y;
}
void multi(com* x, double* y) {
	x->im *= *y;
	x->re *= *y;
}

void my_move(circle& cir, double& x, double& y) {
	cir.x += x;
	cir.y += y;
}
void my_move(circle* cir, double* x, double* y) {
	cir->x += *x;
	cir->y += *y;
}
