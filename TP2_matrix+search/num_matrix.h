#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H
#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

template <typename Numeric>
class MatrixNumerical:
    public MatrixBase<Numeric> {
        public :
        MatrixNumerical();
        MatrixNumerical(size_t rows, size_t cols);

        int getDeterminant() const;
        template <typename Numeric2>
        friend MatrixNumerical<Numeric2> operator + (const MatrixNumerical& M, const MatrixNumerical& N); // numeric2 et pas numeric sinon declaration of template shadows template parameter
        template <typename Numeric2>
        friend MatrixNumerical<Numeric2> operator - (const MatrixNumerical& M, const MatrixNumerical& N);
        template <typename Numeric2>
        friend MatrixNumerical<Numeric2> operator * (const MatrixNumerical& M, const MatrixNumerical& N);
        void getInverse() const; //coFactor à utiliser (hint: d´efinir une fonction hors la classe ‘getCoFactor‘)
        template <typename Numeric2>
        friend MatrixNumerical<Numeric2> operator / (const MatrixNumerical& M, const MatrixNumerical& N);
        static void getIdentity(int n);
    };

template <typename Numeric>
MatrixNumerical<Numeric>::MatrixNumerical():MatrixBase<Numeric>() {}

template <typename Numeric>
MatrixNumerical<Numeric>::MatrixNumerical(size_t rows, size_t cols):MatrixBase<Numeric>(rows, cols) {}

template <typename Numeric>
int MatrixNumerical<Numeric>::getDeterminant() const { 
    Numeric det = 0;
    if (this->rows != this->cols) {
        cout << "Matrix is not square" << endl;
        return 0;
    }
    if (this->rows == 2) { // matrice 2*2 facile à traiter
       det =  this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
        return det;
    }
    for (size_t i = 0; i < this->rows; i++) { // matrice taille n>=3
        MatrixNumerical<Numeric> subMatrix(this->rows - 1, this->cols - 1); // sous-matrice de taille n-1
        for (size_t j = 1; j < this->rows; j++) { // remplissage de la sous-matrice
            for (size_t k = 0; k < this->cols; k++) {
                if (k < i) { // on ajoute que les éléments qui ne sont pas sur la même ligne ou colonne que l'élément de la matrice de base
                    subMatrix.addElement(j - 1, k, this->data[j][k]);
                } else if (k > i) {
                    subMatrix.addElement(j - 1, k - 1, this->data[j][k]);
                }
            }
        }
        det += (i % 2 == 1 ? -1 : 1) * this->data[0][i] * subMatrix.getDeterminant(); // on ajoute ou soustrait le déterminant de la sous-matrice à la valeur du déterminant de la matrice de base
                                                                                      // on alterne entre -1 et 1 pour soustraire ou ajouter
                                                                                      // fonction récursive qui s'arrête quand la sous-matrice est de taille 2
    }
    return det;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator + (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        cout << "Matrices are not of the same size" << endl;
        return MatrixNumerical<Numeric>(0, 0);
    }
    MatrixNumerical<Numeric> result(M.getRows(), M.getCols());
    for (size_t i = 0; i < M.getRows(); i++) {
        for (size_t j = 0; j < M.getCols(); j++) {
            result.addElement(i, j, M.getElement(i, j) + N.getElement(i, j)); //addition de matrice élément par élément
        }
    }
    return result;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator - (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        cout << "Matrices are not of the same size" << endl;
        return MatrixNumerical<Numeric>(0, 0);
    }
    MatrixNumerical<Numeric> result(M.getRows(), M.getCols());
    for (size_t i = 0; i < M.getRows(); i++) {
        for (size_t j = 0; j < M.getCols(); j++) { //soustraction de matrice élément par élément
            result.addElement(i, j, M.getElement(i, j) - N.getElement(i, j));
        }
    }
    return result;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator * (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.getCols() != N.getRows()) {
        cout << "Matrices are not of the same size" << endl;
        return MatrixNumerical<Numeric>(0, 0);
    }
    MatrixNumerical<Numeric> result(M.getRows(), N.getCols());
    for (size_t i = 0; i < M.getRows(); i++) { //multiplication de matrices
        for (size_t j = 0; j < N.getCols(); j++) {
            for (size_t k = 0; k < M.getCols(); k++) {
                result.addElement(i, j, result.getElement(i, j) + M.getElement(i, k) * N.getElement(k, j));
            }
        }
    }
    return result;
}


template <typename Numeric>
void MatrixNumerical<Numeric>::getInverse() const {
    
}

#endif