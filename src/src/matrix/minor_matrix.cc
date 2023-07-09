#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::MinorMatrix(int row, int column) const {
  if (this->GetRows() != this->GetColumns()) {
    throw std::logic_error(
        "Minor matrix could be computed only for square matrices");
  }

  if (this->GetRows() <= 1 || this->GetColumns() <= 1) {
    throw std::logic_error(
        "The empty or one sized matrices doesn't have minors");
  }

  if (row < 0 || row >= this->GetRows()) {
    throw std::range_error("The row number out of range for the matrix.");
  }

  if (column < 0 || column >= this->GetColumns()) {
    throw std::range_error("The columns number out of range for the matrix.");
  }

  int size = this->GetRows() - 1;
  S21Matrix minor(size);

  for (int i = 0, minor_i = 0; i != this->GetRows(); ++i) {
    if (i == row) continue;
    for (int j = 0, minor_j = 0; j < this->GetColumns(); ++j) {
      if (j == column) continue;
      minor(minor_i, minor_j) = (*this)(i, j);
      ++minor_j;
    }
    ++minor_i;
  }

  return minor;
}

}  // namespace s21
