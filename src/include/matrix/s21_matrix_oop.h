#ifndef SRC_INCLUDE_MATRIX_S21_MATRIX_OOP_H_
#define SRC_INCLUDE_MATRIX_S21_MATRIX_OOP_H_

#include <vector>

namespace s21 {

class S21Matrix {
  static constexpr double epsilon_ = 1e-6;

 public:
  S21Matrix();
  explicit S21Matrix(int rows);
  explicit S21Matrix(int rows, int columns);
  S21Matrix(int rows, int columns, std::initializer_list<double> values);
  S21Matrix(int rows, int columns,
            std::initializer_list<std::initializer_list<double>> rows_list);

  inline double Epsilon() const noexcept { return epsilon_; }
  inline int GetRows() const noexcept { return rows_; }
  inline int GetColumns() const noexcept { return columns_; }
  inline const std::vector<double>& GetData() const noexcept { return matrix_; }

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

#endif  // SRC_INCLUDE_MATRIX_S21_MATRIX_OOP_H_
