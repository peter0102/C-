#ifndef COMPLEX2D_H
#define COMPLEX2D_H
#include <iostream>

using namespace std;

class Complex2D {
    public:
        Complex2D();
        Complex2D(double);
        Complex2D(double, double);
        Complex2D(const Complex2D&);

        ostream& print(ostream&) const;

        void set_x(double);
        void set_y(double);
        void set_xy(double, double);

        double get_x();
        double get_y();

        double get_radius() const; //cont indique que la fonction ne peut modifier de variables privées
        double get_theta() const;

        friend Complex2D operator * (const Complex2D&, const Complex2D&);
        friend Complex2D operator / (const Complex2D&, const Complex2D&);
        friend Complex2D operator + (const Complex2D&, const Complex2D&);
        friend Complex2D operator - (const Complex2D&, const Complex2D&);

        Complex2D get_bar() const;
        Complex2D get_inverse() const;

        friend Complex2D operator > (const Complex2D&, const Complex2D&);
        friend Complex2D operator < (const Complex2D&, const Complex2D&);

    private:
        double x;
        double y;
};

#endif