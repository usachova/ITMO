#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() {
    v1.x = 0;
    v1.y = 0;
    v2.x = 0;
    v2.y = 0;
    mass_ = 0;
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double m) {
    v1.x = x1;
    v1.y = y1;
    v2.x = x2;
    v2.y = y2;
    mass_ = m;
}

double Triangle::square() {
	double side = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	return sqrt(3) / 4 * side * side;
}

double Triangle::perimeter() {
	double side = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	return 3 * side;
}

double Triangle::mass() const {
	return mass_;
}

Vector2D Triangle::position() {
	Vector2D answer;
    answer.x = (v1.x + v2.x) / 2;
    answer.y = (v1.y + v2.y) / 2;
    return answer;
}
	
bool Triangle::operator== (const PhysObject& ob) const {
	return mass_ == ob.mass();
}

bool Triangle::operator< (const PhysObject& ob) const {
	return mass_ < ob.mass();
}	

void Triangle::draw() {
    std::cout << "coordinates: (" << v1.x << ", " << v1.y << ") (" << v2.x << ", " << v2.y << ")" << std::endl;
    std::cout << "mass: " << mass_ << std::endl;
}

void Triangle::initFromDialog() {
	std::cout << "enter center coordinates of the triangle points:" << std::endl;;
    std::cin >> v1.x >> v1.y >> v2.x >> v2.y;
    std::cout << "enter mass:" << std::endl;;
    std::cin >> mass_;	
}

const char* Triangle::classname() {
	std::cout << "triangle" << std::endl;
}	

unsigned int Triangle::size() {
	return 8 * 2 + 8 * 2 + 8;
}
