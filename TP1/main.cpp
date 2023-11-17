#include <iostream>
#include <cmath>
#include "complex2d.h"

using namespace std;

int main() {
    Complex2D c1 = Complex2D(4,5);
    Complex2D c2 = Complex2D(3,2);

    Complex2D c3 = c1 + c2;
    Complex2D c4 = c1 - c2;
    
    cout << "Addition/Soustraction" << endl;
    cout << "y1 = " << c1.get_x() << " + " << c1.get_y() << "i" << endl;
    cout << "y2 = " << c2.get_x() << " + " << c2.get_y() << "i" << endl;
    cout << "y1 + y2 = " << c3.get_x() << "+ " << c3.get_y() << "i" << endl;
    cout << "-----------------" << endl;

    Complex2D c5 = c1 * c2;
    Complex2D c6 = c1 / c2;

    cout << "Multiplication/Division" << endl;
    cout << "y1 * y2 = (4+5i)*(3+2i) = 12 + 8i + 15i -10 = 2 + 23i" << endl;
    cout << "y1 * y2 = " << c5.get_x() << " + " << c5.get_y() << "i" << endl;
    cout << "y1 / y2 = (4+5i)/(3+2i) = (12 + 15i)/(9 + 4) = (12 + 15i)/13 = 12/13 + 15/13i" << endl;
    cout << "y1 / y2 = " << c6.get_x() << " + " << c6.get_y() << "i" << endl;
    cout << "-----------------" << endl;

    Complex2D c7 = c1.get_bar();
    Complex2D c8 = c2.get_bar();

    cout << "Conjugaison" << endl;
    cout << "y1 = " << c1.get_x() << " + " << c1.get_y() << "i" << endl;
    cout << "y2 = " << c2.get_x() << " + " << c2.get_y() << "i" << endl;
    cout << "y1* = " << c7.get_x() << " + " << c7.get_y() << "i" << endl;
    cout << "y2* = " << c8.get_x() << " + " << c8.get_y() << "i" << endl;
    cout << "-----------------" << endl;

    Complex2D c9 = c1.get_inverse();
    Complex2D c10 = c2.get_inverse();

    cout << "Inverse" << endl;
    cout << "y1 = " << c1.get_x() << " + " << c1.get_y() << "i" << endl;
    cout << "y2 = " << c2.get_x() << " + " << c2.get_y() << "i" << endl;
    cout << "y1^-1 = " << c9.get_x() << " + " << c9.get_y() << "i" << endl;
    cout << "y2^-1 = " << c10.get_x() << " + " << c10.get_y() << "i" << endl;
    cout << "-----------------" << endl;

    cout << "Module/Argument" << endl;
    Complex2D c1bis = Complex2D(1,1);
    cout << "y1 = " << c1bis.get_x() << " + " << c1bis.get_y() << "i" << endl;
    cout << "Module de y1 = " << c1bis.get_radius() << "soit sqrt(2)" << endl;
    cout << "Argument de y1 = " << c1bis.get_theta() << "soit pi/4" << endl;
    cout << "-----------------" << endl;

    cout << "ostream" << endl;
    ostream &flux = cout;
    c1.print(flux);
    cout << endl;
    cout << "-----------------" << endl;
}