#include <cmath>
#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::InverseMatrix() const {
  // Edge cases
  if (this->Rows() != this->Columns() || this->Rows() == 0) {
    throw std::logic_error(
        "Inverse matrix could be computed only for not empty square matrices");
  }

  double determinant = this->Determinant();

  if (fabs(determinant) < this->Epsilon()) {
    throw std::overflow_error("The determinant is equal zero");
  }

  // Regular cases
  int size = this->Rows();
  s21::S21Matrix transposed_complements = (*this).CalcComplements().Transpose();
  s21::S21Matrix inverse_matrix(size);

  for (int i = 0; i != size; ++i) {
    for (int j = 0; j != size; ++j) {
      inverse_matrix(i, j) = transposed_complements(i, j) / determinant;
    }
  }

  return inverse_matrix;
}

}  // namespace s21
