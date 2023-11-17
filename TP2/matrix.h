#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MatrixBase {
    protected :
        vector<vector<T>> data;
        size_t rows;
        size_t cols;
    public :
        MatrixBase();
        MatrixBase(size_t rows, size_t cols);
        
        void addElement(size_t row, size_t col, T value);
        T getElement(size_t row, size_t col) const;

        size_t getRows() const;
        size_t getCols() const;

        void Display() const;
};

template <typename T>
MatrixBase<T>::MatrixBase():data(1, vector<T>(1, 0)), rows(1), cols(1) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols):data(rows, vector<T>(cols, 0)), rows(rows), cols(cols) {}

template <typename T>
void MatrixBase<T>::addElement(size_t _row, size_t _col, T x) {
    this->data[_row][_col] = x;
}

template <typename T>
T MatrixBase<T>::getElement(size_t _row, size_t _col) const {
    return this->data[_row][_col];
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return this->rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return this->cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            cout << this->data[i][j] << " ";
        }
        cout << endl;
    }
}

#endif