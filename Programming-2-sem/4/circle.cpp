#include "circle.h"
#include <iostream>

Circle::Circle() {
    cen_x = 0;
    cen_y = 0;
    rad = 0;
    mass_ = 0;
}

Circle::Circle(double x, double y, double r, double m) {
    cen_x = x;
    cen_y = y;
    rad = r;
    mass_ = m;
}

double Circle::square() {
	return 3.1415 * rad * rad;
}

double Circle::perimeter() {
	return 2 * 3.1415 * rad;
}

double Circle::mass() const {
	return mass_;
}

Vector2D Circle::position() {
	Vector2D answer;
	answer.x = cen_x;
	answer.y = cen_y;
	return answer;
}
	
bool Circle::operator== (const PhysObject& ob) const {
	return mass_ == ob.mass();
}

bool Circle::operator< (const PhysObject& ob) const {
	return mass_ < ob.mass();
}	

void Circle::draw() {
    std::cout << "center coordinates: (" << cen_x << ", " << cen_y << ")" << std::endl;
    std::cout << "radius: " << rad << std::endl;
    std::cout << "mass: " << mass_ << std::endl;
}

void Circle::initFromDialog() {
	std::cout << "enter center coordinates of the circle:" << std::endl;;
    std::cin >> cen_x >> cen_y;
    std::cout << "enter radius:" << std::endl;;
    std::cin >> rad;
    std::cout << "enter mass:" << std::endl;;
    std::cin >> mass_;	
}

const char* Circle::classname() {
	std::cout << "circle" << std::endl;
}	

unsigned int Circle::size() {
	return 8 * 2 + 8 + 8;
}
