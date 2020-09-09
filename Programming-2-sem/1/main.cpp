#include <iostream>
#include "header.h"

int main() {
	int a1 = 12, b1 = 345;
	std::cout << "1. values:  " << a1 << " " << b1 << std::endl;
	my_swap(a1, b1);
	std::cout << "    with links:  " << a1 << " " << b1 << std::endl;
	my_swap(&a1, &b1);
	std::cout << "    with pointers:  " << a1 << " " << b1 << std::endl;
	
	double a2 = 12.34, b2 = 3.45;
	std::cout << "2. values:  " << a2 << " " << b2 << std::endl;
	my_round(a2);
	std::cout << "    with links:  " << a2 << std::endl;
	my_round(&b2);
	std::cout << "    with pointers:  " << b2 << std::endl;
	
	com a3;
	a3.im = 4;
	a3.re = 8;
	double b3 = 1.5;
	std::cout << "3. values:  " << a3.re << "+" << a3.im << "i " << b3 << std::endl;
	multi(a3, b3);
	std::cout << "    with links:  " << a3.re << "+" << a3.im << "i " << std::endl;
	multi(&a3, &b3);
	std::cout << "    with pointers:  " << a3.re << "+" << a3.im << "i " << std::endl;
	
	circle cir;
	cir.r = 1;
	cir.x = 2;
	cir.y = 3;
	double a4 = 1.25, b4 = 2.15;
	std::cout << "4. values:  " << "(" << cir.x << ";" << cir.y << ")" << " r=" << cir.r << "  {" << a4 << ";" << b4 << "}" << std::endl;
	my_move(cir, a4, b4);
	std::cout << "    with links:  " << "(" << cir.x << ";" << cir.y << ")" << " r=" << cir.r << std::endl;
	my_move(&cir, &a4, &b4);
	std::cout << "    with pointers:  " << "(" << cir.x << ";" << cir.y << ")" << " r=" << cir.r << std::endl;
	return 0;
}
