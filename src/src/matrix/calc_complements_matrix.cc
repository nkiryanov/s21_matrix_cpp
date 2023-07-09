#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::CalcComplements() const {
  if (this->GetRows() != this->GetColumns() || this->GetRows() == 0) {
    throw std::logic_error(
        "Complements matrix could be computed only for not empty square "
        "matrices");
  }

  int size = this->GetRows();
  S21Matrix complements(size);

  for (int i = 0; i != size; ++i) {
    for (int j = 0; j != size; ++j) {
      int sign = ((i + j) % 2 == 0) ? 1 : -1;
      complements(i, j) = sign * (*this).MinorMatrix(i, j).Determinant();
    }
  }

  return complements;
}
}  // namespace s21
