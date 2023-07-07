#include <algorithm>
#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {
void S21Matrix::SetRows(int desired_rows) {
  // Edge cases
  if (desired_rows == this->Rows()) return;

  if (desired_rows < 0) {
    throw std::length_error("The number or rows couldn't be less than zero");
  }

  S21Matrix resized_matrix(desired_rows, this->Columns());

  int rows_index_to_copy = std::min(this->Rows(), desired_rows);

  for (int i = 0; i != rows_index_to_copy; ++i) {
    for (int j = 0; j != this->Columns(); ++j) {
      resized_matrix(i, j) = (*this)(i, j);
    }
  }

  std::swap(*this, resized_matrix);
}

void S21Matrix::SetColumns(int desired_columns) {
  // Edge cases
  if (desired_columns == this->Columns()) return;

  if (desired_columns <= 0) {
    throw std::length_error("The number or columns couldn't be less than zero");
  }

  S21Matrix resized_matrix(this->Rows(), desired_columns);

  int columns_index_to_copy = std::min(this->Columns(), desired_columns);

  for (int i = 0; i != this->Rows(); ++i) {
    for (int j = 0; j != columns_index_to_copy; ++j) {
      resized_matrix(i, j) = (*this)(i, j);
    }
  }

  std::swap(*this, resized_matrix);
}

}  // namespace s21
