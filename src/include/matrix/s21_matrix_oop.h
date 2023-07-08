#ifndef MATRIX_S21_MATRIX_OOP_H_
#define MATRIX_S21_MATRIX_OOP_H_

#include <vector>

namespace s21 {

class S21Matrix {
  static constexpr double epsilon_ = 10e-7;

 public:
  S21Matrix();
  explicit S21Matrix(int rows);
  explicit S21Matrix(int rows, int columns);
  S21Matrix(int rows, int columns, std::initializer_list<double> values);
  S21Matrix(int rows, int columns,
            std::initializer_list<std::initializer_list<double>> rows_list);

  double Epsilon() const noexcept;
  int Rows() const noexcept;
  int Columns() const noexcept;
  const std::vector<double>& Data() const noexcept;
  void SetRows(int desired_rows);
  void SetColumns(int desired_columns);

  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SubMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void MulNumber(double number) noexcept;
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose() const noexcept;
  S21Matrix MinorMatrix(int row, int column) const;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  const double& operator()(int row, int column) const;
  double& operator()(int row, int column);
  bool operator==(const S21Matrix& other) const noexcept;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator*(double number) const;
  S21Matrix& operator*=(double number);

 private:
  int rows_;
  int columns_;
  std::vector<double> matrix_;
};

S21Matrix operator*(double number, const S21Matrix& matrix);

}  // namespace s21

#endif  // MATRIX_S21_MATRIX_OOP_H_
