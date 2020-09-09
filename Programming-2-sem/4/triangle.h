#pragma once

#include "header.h"

class Triangle:
    public IGeoFig, 
	public Vector2D,
    public PhysObject,
    public Printable,
    public DialogInitiable,
    public BaseObject {    	
private:
	Vector2D v1, v2;
	double mass_;
	
public:
	Triangle();
	Triangle(double, double, double, double, double);
	
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
