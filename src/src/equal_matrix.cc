#include <cmath>
#include <stdexcept>

#include "matrix/s21_matrix_oop.h"

namespace s21 {

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (this->Rows() != other.Rows() || this->Columns() != other.Columns()) {
    return false;
  }

  for (size_t i = 0; i != this->matrix_.size(); ++i) {
    if (fabs(this->matrix_[i] - other.matrix_[i]) > this->epsilon_) {
      return false;
    }
  }

  return true;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  return this->EqMatrix(other);
}

}  // namespace s21
