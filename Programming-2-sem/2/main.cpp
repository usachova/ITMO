#include "header.h"

int main() {
	std::cout << "enter complex number:" << std::endl;
	Complex z;
	std::cin >> z;
	std::cout << "enter real number:" << std::endl;
	double a;
	std::cin >> a;
	std::cout << "(" << z << ") * " << a << " = " << z * a << std::endl;
	
	std::cout << "enter complex number:" << std::endl;
	Complex z1;
	std::cin >> z1;
	std::cout << "enter comlex number:" << std::endl;
	Complex z2;
	std::cin >> z2;
	std::cout << "(" << z1 << ") + (" << z2 << ") = " << z1 + z2 << std::endl;
	
	std::cout << "enter complex number:" << std::endl;
	Complex z3;
	std::cin >> z3;
	std::cout << "enter comlex number:" << std::endl;
	Complex z4;
	std::cin >> z4;
	std::cout << "(" << z3 << ") * (" << z4 << ") = " << z3 * z4 << std::endl;
	return 0;
}
