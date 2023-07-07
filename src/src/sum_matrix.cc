#include <stdexcept>

#include "s21_matrix_oop.h"

namespace s21 {

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
    throw std::invalid_argument(
        "Summing matrices have to have the same dimension.");
  }

  for (size_t i = 0; i != this->matrix_.size(); ++i) {
    this->matrix_[i] += other.matrix_[i];
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);

  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return (*this);
}

}  // namespace s21
