#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H
#include <iostream>
#include <vector>

using namespace std;

template <typename Numeric>
class MatrixNumerical:
    public MatrixBase<Numeric> {
        public :
        MatrixNumerical();
        MatrixNumerical(size_t rows, size_t cols);

        int getDeterminant() const;
        MatrixNumerical operator + (const MatrixNumerical& M, const MatrixNumerical& N);
        MatrixNumerical operator - (const MatrixNumerical& M, const MatrixNumerical& N);
        MatrixNumerical operator * (const MatrixNumerical& M, const MatrixNumerical& N);
        void getInverse() const; //coFactor à utiliser (hint: d´efinir une fonction hors la classe ‘getCoFactor‘)
        MatrixNumerical operator / (const MatrixNumerical& M, const MatrixNumerical& N);
        static void getIdentity(size_t int) const;
    };

template <typename Numeric>
MatrixNumerical<Numeric>::MatrixNumerical():data(1, vector<Numeric>(1, 0)), rows(1), cols(1) {}

template <typename Numeric>
MatrixNumerical<Numeric>::MatrixNumerical(size_t rows, size_t cols):data(rows, vector<Numeric>(cols, 0)), rows(rows), cols(cols) {}

template <typename Numeric>
int MatrixNumerical<Numeric>::getDeterminant() const { 
    Numeric det = 0;
    if (this->rows != this->cols) {
        cout << "Matrix is not square" << endl;
        return;
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
    return det
}

template <typename Numeric>
MatrixNumerical<Numeric> operator + (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.rows != N.rows || M.cols != N.cols) {
        cout << "Matrices are not of the same size" << endl;
        return;
    }
    MatrixNumerical<Numeric> result(M.rows, M.cols);
    for (size_t i = 0; i < M.rows; i++) {
        for (size_t j = 0; j < M.cols; j++) {
            result.addElement(i, j, M.data[i][j] + N.data[i][j]); //addition de matrice élément par élément
        }
    }
    return result;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator - (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.rows != N.rows || M.cols != N.cols) {
        cout << "Matrices are not of the same size" << endl;
        return;
    }
    MatrixNumerical<Numeric> result(M.rows, M.cols);
    for (size_t i = 0; i < M.rows; i++) {
        for (size_t j = 0; j < M.cols; j++) { //soustraction de matrice élément par élément
            result.addElement(i, j, M.data[i][j] - N.data[i][j]);
        }
    }
    return result;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator * (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.cols != N.rows) {
        cout << "Matrices are not of the same size" << endl;
        return;
    }
    MatrixNumerical<Numeric> result(M.rows, N.cols);
    for (size_t i = 0; i < M.rows; i++) { //multiplication de matrices
        for (size_t j = 0; j < N.cols; j++) {
            for (size_t k = 0; k < M.cols; k++) {
                result.addElement(i, j, result.data[i][j] + M.data[i][k] * N.data[k][j]);
            }
        }
    }
    return result;
}

template <typename Numeric>
MatrixNumerical<Numeric> operator / (const MatrixNumerical<Numeric>& M, const MatrixNumerical<Numeric>& N) {
    if (M.cols != N.rows) {
        cout << "Matrices are not of the same size" << endl;
        return;
    }
    MatrixNumerical<Numeric> result(M.rows, N.cols);
    for (size_t i = 0; i < M.rows; i++) {
        for (size_t j = 0; j < N.cols; j++) {
            for (size_t k = 0; k < M.cols; k++) {
                result.addElement(i, j, result.data[i][j] + M.data[i][k] / N.data[k][j]);
            }
        }
    }
    return result;
}

template <typename Numeric>
void MatrixNumerical<Numeric>::getInverse() {
    
}

#endif