#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <vector>

namespace s21 {

class S21Matrix {
  static constexpr double epsilon_ = 10e-7;

 private:
  int rows_;
  int columns_;
  std::vector<double> matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows);
  S21Matrix(int rows, int columns);
  S21Matrix(int rows, int columns, std::initializer_list<double> values);

  double Epsilon() const;
  int Rows() const;
  int Columns() const;
  const std::vector<double>& Data() const;

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void MulMatrix(const S21Matrix& other);

  const double& operator()(int row, int column) const;
  double& operator()(int row, int column);
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
};

}  // namespace s21

#endif  // S21_MATRIX_OOP_H_
