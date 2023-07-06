#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->columns_ != other.rows_) {
    throw std::invalid_argument(
        "Number of columns of the matrix has to be equal number or rows of "
        "second matrix");
  }

  int rows = this->rows_;
  int columns = other.columns_;
  S21Matrix result(this->rows_, other.columns_);

  for (int i = 0; i != rows; ++i) {
    for (int j = 0; j != columns; ++j) {
      for (int k = 0; k != this->columns_; ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }

  *this = std::move(result);
}

}  // namespace s21