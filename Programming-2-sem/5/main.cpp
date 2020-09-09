#include <iostream>
#include "header.h"

int main() {
	std::vector<int> arr(3);
	arr[0] = 0;
	arr[1] = 42;
	arr[2] = -1;
	std::cout << "my vector: ";
	for (int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "max element: " << max_el(arr) << std::endl;
	
	std::cout << "initializing stack with max size = 2" << std::endl;
	stack<int> st(2);
	std::cout << "trying to add 2 elements: ";
	try {
		st.push(1);
		st.push(2);
	}
	catch (...) {
		std::cout << "stack is full";
	}
	std::cout << "success!" << std::endl;
	std::cout << "trying to remove 3 elements: ";
	try {
		st.pop();
		st.pop();
		st.pop();
	}
	catch (...) {
		std::cout << "stack is empty";
	}
	return 0;
}
