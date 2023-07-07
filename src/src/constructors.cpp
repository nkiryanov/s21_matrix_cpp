#include <initializer_list>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

static int VerifyRange(int matrix_dimension) {
  if (matrix_dimension <= 0) {
    throw std::invalid_argument("Row or colons must be positive");
  }

  return matrix_dimension;
}

static std::initializer_list<double>& VerifyInitializerList(
    int rows, int columns, std::initializer_list<double>& matrix_values) {
  if ((size_t)(rows * columns) != matrix_values.size()) {
    throw std::invalid_argument("Provided values not match the matrix size");
  }

  return matrix_values;
}

S21Matrix::S21Matrix() : rows_(0), columns_(0), matrix_(0) {}

S21Matrix::S21Matrix(int rows, int columns)
    : rows_(VerifyRange(rows)),
      columns_(VerifyRange(columns)),
      matrix_(rows * columns, 0) {}

S21Matrix::S21Matrix(int size) : S21Matrix(size, size) {}

S21Matrix::S21Matrix(int rows, int columns,
                     std::initializer_list<double> matrix_values)
    : rows_(VerifyRange(rows)),
      columns_(VerifyRange(columns)),
      matrix_(VerifyInitializerList(rows, columns, matrix_values)) {}

}  // namespace s21
