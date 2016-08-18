#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

namespace calculations {

template< class T >
class Matrix {
public:
    Matrix();

    Matrix (T* A, T* B, int dim) : A_(A), B_(B), dim_(dim) {}

    T* multiplay() {
        result_ = new T[dim_ * dim_];
        for (int row = 0; row < dim_; row++) {
            for (int col = 0; col < dim_; col++) {
                T tempResult = 0;
                for (int i = 0; i < dim_; i++) {
                    tempResult += A_[(row * dim_) + i] * B_[col + (dim_ * i)];
                }
                result_[(row * dim_) + col] = tempResult;
            }
        }
        return result_;
    }

    void printResult () {
        for (int row = 0; row < dim_; row++) {
            for (int col = 0; col < dim_; col++) {
                int indxRow = col + row * dim_;
                std::cout << result_[indxRow] << " ";
            }
            std::cout << "\n";
        }
    }

    ~Matrix() {}

private:
    T *A_, *B_, *result_;
    int dim_;
};
}

#endif
