#include "complex2d.h"
#include <cmath>
#include <iostream>

using namespace std;

Complex2D::Complex2D() {
    x = 0;
    y = 0;
}
Complex2D::Complex2D(double x):x(x) {}
Complex2D::Complex2D(double x, double y):x(x),y(y) {}
Complex2D::Complex2D(const Complex2D& c):x(c.x),y(c.y) {}

void Complex2D::set_x(double x) {
    this->x = x;
}

void Complex2D::set_y(double y) {
    this->y = y;
}

void Complex2D::set_xy(double x, double y) {
    this->x = x;
    this->y = y;
}

double Complex2D::get_x() {
    return x;
}
double Complex2D::get_y() {
    return y;
}

double Complex2D::get_radius() const {
    return sqrt(x*x + y*y);
}

double Complex2D::get_theta() const {
    return atan2(y,x);
}

Complex2D operator - (const Complex2D& x, const Complex2D& y) {
    return Complex2D(x.x - y.x, x.y - y.y);
}

Complex2D operator + (const Complex2D& x, const Complex2D& y) {
    return Complex2D(x.x + y.x, x.y + y.y);
}

Complex2D operator * (const Complex2D& x, const Complex2D& y) {
    return Complex2D(x.x*y.x - x.y*y.y, x.x*y.y + x.y*y.x);
}

Complex2D operator / (const Complex2D& x, const Complex2D& y) {
    return Complex2D((x.x*y.x + x.y*y.y)/(y.x*y.x + y.y*y.y), (x.y*y.x - x.x*y.y)/(y.x*y.x + y.y*y.y));
}

Complex2D Complex2D::get_bar() const {
    return Complex2D(x,-y);
}

Complex2D Complex2D::get_inverse() const {
    return Complex2D(x/(x*x + y*y), -y/(x*x + y*y));
}

ostream& Complex2D::print(ostream& out) const {
    out << x << " + " << y << "i";
    return out;
}