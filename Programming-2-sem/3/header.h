#pragma once
#include <iostream>
#include <math.h>

class Complex {
	private:
		double im;
		double re;
	
	public:
		Complex() = default;
		Complex(double);
		Complex(double, double);
		Complex(const Complex&);
		~Complex() = default;
		
		double length() const;
		
		Complex& operator=(Complex&);
		Complex operator*(double);
		Complex operator+(Complex&);
		Complex operator*(Complex&);
		
		friend std::ostream& operator<<(std::ostream&, const Complex&);
    	friend std::istream& operator>>(std::istream&, Complex&);
};

struct node {
	int value;
	node* p;
};

class Stack {	
	public:
		node* top;
		
		Stack();
		~Stack();
		
		void operator<<(const int&);
		void operator>>(const int&);
};

void printStack(const Stack&);
