#include "s21_matrix_oop.h"

namespace s21 {

void S21Matrix::MulNumber(double number) {
  for (auto& cell_value : this->matrix_) {
    cell_value *= number;
  }
}

S21Matrix S21Matrix::operator*(double number) const {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

S21Matrix& S21Matrix::operator*=(double number) {
  this->MulNumber(number);
  return *this;
}

S21Matrix operator*(double number, const S21Matrix& matrix) {
  return matrix * number;
}

}  // namespace s21
