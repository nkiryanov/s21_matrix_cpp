#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

static void VerifyRanges(int row, int column, const S21Matrix& matrix) {
  if (row < 0 || column < 0) {
    throw std::out_of_range("Index of row or column could not be less zero");
  }

  if (row >= matrix.Rows()) {
    throw std::out_of_range(
        "Index of row must be less the number of matrix rows");
  }

  if (column >= matrix.Columns()) {
    throw std::out_of_range(
        "Index of column must be less the number of matrix columns");
  }
}

const double& S21Matrix::operator()(int row, int column) const {
  VerifyRanges(row, column, *this);

  return this->Data()[row * this->Columns() + column];
}

double& S21Matrix::operator()(int row, int column) {
  VerifyRanges(row, column, *this);

  return this->Data()[row * this->Columns() + column];
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);

  return result;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  (*this).MulMatrix(other);
  return *this;
}

}  // namespace s21
