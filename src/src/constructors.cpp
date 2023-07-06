#include <initializer_list>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix::S21Matrix() : rows_(0), columns_(0) {}

S21Matrix::S21Matrix(int rows, int columns) : rows_(rows), columns_(columns) {
  if (rows_ <= 0 || columns_ <= 0) {
    throw std::invalid_argument("Row or colons must be positive");
  }

  matrix_.resize(rows * columns);
}

S21Matrix::S21Matrix(int size) : S21Matrix(size, size) {}

S21Matrix::S21Matrix(int rows, int columns,
                     std::initializer_list<double> matrix_values)
    : S21Matrix(rows, columns) {
  if ((size_t)(rows * columns) != matrix_values.size()) {
    throw std::invalid_argument("Provided values not match the matrix size");
  }

  matrix_ = matrix_values;
}

}  // namespace s21
