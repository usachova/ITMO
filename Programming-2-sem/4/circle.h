#pragma once

#include "header.h"

class Circle:
    public IGeoFig, 
	public Vector2D,
    public PhysObject,
    public Printable,
    public DialogInitiable,
    public BaseObject {    	
private:
	double cen_x, cen_y;
	double rad;
	double mass_;
	
public:
	Circle();
	Circle(double, double, double, double);
	
	double square() override;
	double perimeter() override;
	double mass() const override;
	Vector2D position() override;
	bool operator== (const PhysObject& ob) const override;
	bool operator< (const PhysObject& ob) const override;
	void draw() override;
	void initFromDialog() override;
	const char* classname() override;
	unsigned int size() override;
};
