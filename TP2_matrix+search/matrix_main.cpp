#include"matrix.h"
#include"num_matrix.h"
#include<iostream>

using namespace std;

int main(){

    MatrixNumerical<double> M(3,3);

    M.addElement(0,0,1);
    M.addElement(0,1,2);
    M.addElement(0,2,3);
    M.addElement(1,0,4);
    M.addElement(1,1,5);
    M.addElement(1,2,6);
    M.addElement(2,0,7);
    M.addElement(2,1,8);
    M.addElement(2,2,9);

    MatrixNumerical<double> N(3,3);

    N.addElement(0,0,1);
    N.addElement(0,1,2);
    N.addElement(0,2,3);
    N.addElement(1,0,4);
    N.addElement(1,1,5);
    N.addElement(1,2,6);
    N.addElement(2,0,7);
    N.addElement(2,1,8);
    N.addElement(2,2,9);

    cout << "Matrice M" << endl;
    M.Display();
    cout << "Matrice N" << endl;
    N.Display();
    cout << "Matrice M+N" << endl;
    (M+N).Display();
    cout << "Matrice M-N" << endl;
    (M-N).Display();
    cout << "Matrice M*N" << endl;
    (M*N).Display();
    cout << "det(M)" << endl;
    cout << M.getDeterminant() << endl;

    return 0;
}