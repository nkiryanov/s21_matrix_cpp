#include "s21_matrix_oop.h"

#include <stdexcept>

namespace s21 {

S21Matrix::S21Matrix(int rows, int columns) : rows_(rows), columns_(columns) {
  if (rows_ <= 0 || columns_ <= 0) {
    throw std::length_error("Matrix could have only positive rows or columns");
  }

  matrix_ = new double[rows_ * columns];
}

S21Matrix::S21Matrix(int size) : S21Matrix(size, size) {}
S21Matrix::S21Matrix() : S21Matrix(3) {}

int S21Matrix::Rows() {return rows_;}
int S21Matrix::Columns() {return columns_;}

}  // namespace s21
