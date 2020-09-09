#pragma once

template<class it_b, class it_e, class pred>
bool all_of(it_b begin, it_e end, pred pr) {
	while (begin != end) {
		if (!pr(*begin)) return false;
		begin++;
	}
	return true;
}

template<class it_b, class it_e, class compare>
bool is_sorted(it_b begin, it_e end, compare comp) {
	if (begin == end) return true;
	it_b next = begin + 1;
	while (next != end) {
		if (!comp(*begin, *next)) return false;
		begin++;
		next++;
	}
	return true;
}

template<class it_b, class it_e, class T>
auto find_backward(it_b begin, it_e end, const T& val) {
	while (begin != end) {
		if ((*end) == val) return end;
		end--;
	}
	return begin;
}
