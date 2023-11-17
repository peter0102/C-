#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H
#include <iostream>
#include <vector>

using namespace std;

template <typename NumericalType>
class MatrixNumerical:
    public MatrixBase<NumericalType> {
        protected :
        MatrixNumerical();
        MatrixNumerical(size_t rows, size_t cols);

        public :
        void getDeterminant() const;
        MatrixNumerical operator + (const MatrixNumerical& M, const MatrixNumerical& N) const;
        MatrixNumerical operator - (const MatrixNumerical& M, const MatrixNumerical& N) const;
        MatrixNumerical operator * (const MatrixNumerical& M, const MatrixNumerical& N) const;
        void getInverse() const; //coFactor à utiliser (hint: d´efinir une fonction hors la classe ‘getCoFactor‘)
        MatrixNumerical operator / (const MatrixNumerical& M, const MatrixNumerical& N) const;
        static void getIdentity(size_t int) const;
    };
#endif