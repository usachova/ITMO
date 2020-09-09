#pragma once

#include "circle.h"
#include "triangle.h"
#include <vector>

class Menu {
private:
	int type;
    std::vector<Circle> circles;
    std::vector<Triangle> triangles;
    
public:
    Menu();

    void set();
    void doit();
};
