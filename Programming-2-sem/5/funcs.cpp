#include "header.h"

stack_exc::stack_exc(const char* str) : str(str) {}

const char* stack_exc::what() const noexcept {
	return str;
}
