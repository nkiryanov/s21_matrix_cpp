#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

double S21Matrix::Determinant() const {
  // Edge cases
  if (this->Rows() != this->Columns() || this->Rows() == 0) {
    throw std::logic_error(
        "Determinant could be computed only for not empty square matrices");
  }

  // Regular case
  int size = this->Rows();

  if (size == 1) {
    return (*this)(0, 0);
  }

  double determinant = 0;

  for (int j = 0, sign = 1; j != size; ++j) {
    S21Matrix minor_matrix = this->MinorMatrix(0, j);  // Calculate by first row
    double minor_determinant = minor_matrix.Determinant();
    determinant += sign * (*this)(0, j) * minor_determinant;
    sign *= -1;
  }

  return determinant;
}

}  // namespace s21
