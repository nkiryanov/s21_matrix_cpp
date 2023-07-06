#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <vector>

namespace s21 {

class S21Matrix {
 private:
  int rows_;
  int columns_;
  std::vector<double> matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows);
  S21Matrix(int rows, int columns);
  S21Matrix(int rows, int columns, std::initializer_list<double> values);

  int Rows() const;
  int Columns() const;
  std::vector<double>& Data();
  const std::vector<double>& Data() const;

  void MulMatrix(const S21Matrix& other);

  const double& operator()(int row, int column) const;
  double& operator()(int row, int column);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
};

}  // namespace s21

#endif  // S21_MATRIX_OOP_H_
