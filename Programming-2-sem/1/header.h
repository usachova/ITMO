#pragma once

void my_swap(int& a, int& b);
void my_swap(int* a, int* b);

void my_round(double& x);
void my_round(double* x);

struct com {
	double re;
	double im;
};
void multi(com& x, double& y);
void multi(com* x, double* y);

struct circle {
	double x;
	double y;
	double r;
};
void my_move(circle& cir, double& x, double& y);
void my_move(circle* cir, double* x, double* y);
