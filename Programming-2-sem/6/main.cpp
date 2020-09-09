#include "header.h"
#include "struct.h"
#include <iostream>
#include <vector>

int main() {
	std::cout << "task 1:" << std::endl;
	std::vector<int> vec = {0, 1, 2, 42};
	std::cout << "    vector:";
	for (int i = 0; i < vec.size(); i++) std::cout << " " << vec[i];
	std::cout << std::endl;
	std::cout << "    are all of vector's elements even numbers? ";
	if (all_of(vec.begin(), vec.end(), [](int v) { return (v % 2) == 0; })) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	std::vector<point> points(5);
	for (int i = 0; i < points.size(); i++) {
		points[i].x = 2 * i + 1;
		points[i].y = i - 1;
	}
	std::cout << "    vector:";
	for (int i = 0; i < points.size(); i++) std::cout << " (" << points[i].x << "," << points[i].y << ")";
	std::cout << std::endl;
	std::cout << "    are all of vector's elements has odd abscissa? ";
	if (all_of(points.begin(), points.end(), [](point v) { return v.x % 2; })) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	std::cout << std::endl;
	
	std::cout << "task 2:" << std::endl;
	std::vector<int> vec2 = {-1, 2, 3, -2};
	std::cout << "    vector:";
	for (int i = 0; i < vec2.size(); i++) std::cout << " " << vec2[i];
	std::cout << std::endl;
	std::cout << "    is vector sorted? ";
	if (is_sorted(vec2.begin(), vec2.end(), [](int v1, int v2) { return v1 < v2; })) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	std::vector<point> points2(6);
	for (int i = 0; i < points2.size(); i++) {
		points2[i].x = 2 * i + 1;
		points2[i].y = i - 1;
	}
	std::cout << "    vector:";
	for (int i = 0; i < points2.size(); i++) std::cout << " (" << points2[i].x << "," << points2[i].y << ")";
	std::cout << std::endl;
	std::cout << "    is vector sorted by ordinate? ";
	if (is_sorted(points2.begin(), points2.end(), [](point v1, point v2) { return v1.y < v2.y; })) std::cout << "true" << std::endl;
	else std::cout << "false" << std::endl;
	std::cout << std::endl;
	
	std::cout << "task 3:" << std::endl;
	std::vector<int> vec3 = {-1, 2, 42, 2, -1};
	std::cout << "    vector:";
	for (int i = 0; i < vec3.size(); i++) std::cout << " " << vec3[i];
	std::cout << std::endl;
	std::cout << "    where is 42? ";
	std::cout << find_backward(vec3.begin(), vec3.end(), 42) - vec3.begin() << std::endl;
	std::vector<point> points3(4);
	for (int i = 0; i < points3.size(); i++) {
		points3[i].x = 2 * i + 1;
		points3[i].y = i - 1;
	}
	return 0;
}
