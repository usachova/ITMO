#include "header.h"

int main() {
	Complex z1(1, 2), z2(3, 4);
	double a = 2.33;
	std::cout << "(" << z1 << ") * " << a << " = " << z1 * a << std::endl;
	std::cout << "(" << z1 << ") + (" << z2 << ") = " << z1 + z2 << std::endl;
	std::cout << "(" << z1 << ") * (" << z2 << ") = " << z1 * z2 << std::endl;
	std::cout << "|" << z1 << "| = " << z1.length() << std::endl;
	std::cout << std::endl;
	
	Stack st;
	st << 41;
	st << 42;
	st << 43;
	st << -1;
	std::cout << "stack's elements: ";
	printStack(st);
	std::cout << std::endl;
	st >> -1;
	std::cout << "removed the last one: ";
	printStack(st);
}
