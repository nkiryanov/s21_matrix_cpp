#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

static void VerifyRanges(int row, int column, const S21Matrix& matrix) {
  if (row < 0 || column < 0) {
    throw std::out_of_range("Index of row or column could not be less zero");
  }

  if (row >= matrix.GetRows()) {
    throw std::out_of_range(
        "Index of row must be less the number of matrix rows");
  }

  if (column >= matrix.GetColumns()) {
    throw std::out_of_range(
        "Index of column must be less the number of matrix columns");
  }
}

const double& S21Matrix::operator()(int row, int column) const {
  VerifyRanges(row, column, *this);

  return this->GetData()[row * this->GetColumns() + column];
}

double& S21Matrix::operator()(int row, int column) {
  VerifyRanges(row, column, *this);

  return this->matrix_[row * this->GetColumns() + column];
}

}  // namespace s21
