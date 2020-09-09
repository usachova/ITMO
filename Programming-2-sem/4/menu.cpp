#include "menu.h"
#include <iostream>
#include <algorithm>

Menu::Menu() {
    type = 0;
}

void Menu::set() {
    std::cout << "choose type of the operation:" << std::endl;
    std::cout << "1 if you want to add circle" << std::endl;
    std::cout << "2 if you want to add triangle" << std::endl;
    std::cout << "3 if you want to see all figures" << std::endl;
    std::cout << "4 if you want to know area of figures" << std::endl;
    std::cout << "5 if you want to know total perimeter of figures" << std::endl;
    std::cout << "6 if you want to know center mass of all figures" << std::endl;
    std::cout << "7 if you want to know total memory that objects occupy" << std::endl;
    std::cout << "8 if you want to sort all figures by mass" << std::endl;
    std::cin >> type;
}

bool comp_c(Circle c1, Circle c2) {
	return c1.mass() < c2.mass();
}

bool comp_t(Triangle t1, Triangle t2) {
	return t1.mass() < t2.mass();
}

void Menu::doit() {
    Circle ci;
    Triangle tr;
    double sq = 0, per = 0, sum_m = 0, sum_s = 0, xc = 0, yc = 0;
    switch (type) {
        case 0:
            std::cout << "type of operation not found" << std::endl;
            break;
        case 1:
        	ci.initFromDialog();
        	circles.push_back(ci);
            break;
        case 2:
            tr.initFromDialog();
            triangles.push_back(tr);
            break;
        case 3:
            std::cout << "all figures:" << std::endl;
            for (int i = 0; i < circles.size(); i++) {
                std::cout << i + 1 << " circle:" << std::endl;
                circles[i].draw();
            }
            for (int i = 0; i < triangles.size(); i++) {
                std::cout << i + 1 << " triangle:" << std::endl;
                triangles[i].draw();
            }
            break;
        case 4:
        	for (int i = 0; i < circles.size(); i++) sq += circles[i].square();
        	for (int i = 0; i < triangles.size(); i++) sq += triangles[i].square();
            std::cout << "total area = " << sq << std::endl;
            break;
        case 5:
        	for (int i = 0; i < circles.size(); i++) per += circles[i].perimeter();
        	for (int i = 0; i < triangles.size(); i++) per += triangles[i].perimeter();
            std::cout << "total perimeter = " << per << std::endl;
            break;
        case 6:
        	for (int i = 0; i < circles.size(); i++) {
        		sum_m += circles[i].mass();
        		Vector2D pos = circles[i].position();
        		xc += pos.x;
        		yc += pos.y;
            }
            for (int i = 0; i < triangles.size(); i++) {
        		sum_m += triangles[i].mass();
        		Vector2D pos = triangles[i].position();
        		xc += pos.x;
        		yc += pos.y;
            }
            xc /= sum_m;
            yc /= sum_m;
            std::cout << "center mass: (" << xc << ", " << yc << ")" << std::endl;
            break;
        case 7:
        	for (int i = 0; i < circles.size(); i++) sum_s += circles[i].size();
        	for (int i = 0; i < triangles.size(); i++) sum_s += triangles[i].size();
            std::cout << "total memory = " << sum_s << std::endl;
            break;
        case 8:
            std::sort(circles.begin(), circles.end(), comp_c);
            std::sort(triangles.begin(), triangles.end(), comp_t);
            break;
        default:
            std::cout << "wrong type" << std::endl;
            break;
    }
}
