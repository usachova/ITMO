#include "header.h"

Complex::Complex(double r) : re(r), im(0) {
}

Complex::Complex(double r, double i) : re(r), im(i) {
}

Complex::Complex(const Complex& z) {
	re = z.re;
	im = z.im;
}

double Complex::length() const {
	return sqrt(pow(re, 2) + pow(im, 2));
}

Complex& Complex::operator=(Complex& z) {
	re = z.re;
	im = z.im;
	return *this;
}

Complex Complex::operator*(double a) {
	return Complex(re * a, im * a);
}

Complex Complex::operator+(Complex& z) {
	return Complex(re + z.re, im + z.im);
}

Complex Complex::operator*(Complex& z) {
	return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}

std::ostream& operator<<(std::ostream& out, const Complex& z) {
	out << z.re << (z.im >= 0 ? "+" : "") << z.im << "i";
	return out;
}

std::istream& operator>>(std::istream& in, Complex& z) {
	in >> z.re >> z.im;
	return in;
}
