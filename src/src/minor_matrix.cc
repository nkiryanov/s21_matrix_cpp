#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::MinorMatrix(int row, int column) const {
  // Edge cases
  if (this->Rows() != this->Columns()) {
    throw std::logic_error(
        "Minor matrix could be computed only for square matrices");
  }

  if (this->Rows() <= 1 || this->Columns() <= 1) {
    throw std::logic_error(
        "The empty or one sized matrices doesn't have minors");
  }

  if (row < 0 || row >= this->Rows()) {
    throw std::range_error("The row number out of range for the matrix.");
  };

  if (column < 0 || column >= this->Columns()) {
    throw std::range_error("The columns number out of range for the matrix.");
  }

  // Regular case
  int size = this->Rows() - 1;
  S21Matrix minor(size);

  for (int i = 0, minor_i = 0; i != this->Rows(); ++i) {
    if (i == row) continue;
    for (int j = 0, minor_j = 0; j < this->Columns(); ++j) {
      if (j == column) continue;
      minor(minor_i, minor_j) = (*this)(i, j);
      ++minor_j;
    }
    ++minor_i;
  }

  return minor;
}

}  // namespace s21