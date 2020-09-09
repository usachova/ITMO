#pragma once
#include <vector>
#include <list>

template<typename T>
T max_el(std::vector<T> arr) {
	T max;
	if (arr.size() > 0) max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

class stack_exc : std::exception {
	private:
		const char* str;
	public:
		explicit stack_exc(const char*);
		const char* what() const noexcept override;
};

template<class T>
class stack {
	private:
		std::list<T> my_list;
		unsigned size;
	public:
		stack(const int&n) : size(n) {}
		
		void push(const T& value) {
			if (my_list.size() == size) {
				throw stack_exc("stack is full");
			}
			my_list.push_back(value);
		}
		
		T pop() {
			if (my_list.size() == 0) {
				throw stack_exc("stack is empty");
			}
			my_list.pop_back();
		}
};
