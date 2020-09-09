#include <iostream>
#include "menu.h"

int main() {
	Menu m;
	int flag = 1;
	while (flag == 1) {
		m.set();
		m.doit();
        std::cout << "enter 1 if you want to continue yes or 2 if you do not" << std::endl;
        std::cin >> flag;
	}
	return 0;
}
