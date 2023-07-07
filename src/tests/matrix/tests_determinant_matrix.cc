#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixDeterminant, MatrixDeterminantComputedOk) {
  const s21::S21Matrix matrix(4, 4,
                              {
                                  {1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16},
                              });

  double determinant = matrix.Determinant();

  EXPECT_NEAR(determinant, 0.0, matrix.Epsilon());
}

TEST(MatrixDeterminant, MatrixDeterminantForOneElementMatrix) {
  const s21::S21Matrix matrix(1, 1, {686.686595});

  double determinant = matrix.Determinant();

  EXPECT_NEAR(determinant, 686.686595, matrix.Epsilon());
}

TEST(MatrixDeterminant, MatrixSizeSeverComputesOkAsWell) {
  const s21::S21Matrix matrix(
      7, 7,
      {
          {3.54155, 2.53027, 2.52268, 3.32609, 1.74077, 1.84826, 2.31548},
          {1.79850, 1.03137, 3.21930, 2.23851, 3.69014, 1.86757, 2.58197},
          {3.12373, 2.50464, 2.81140, 3.95159, 3.93592, 2.55369, 2.85939},
          {2.53200, 2.17887, 3.89360, 2.57050, 1.35048, 2.86216, 2.85716},
          {2.45656, 2.44057, 3.60225, 2.02151, 2.66313, 3.54608, 1.99800},
          {2.73763, 3.62892, 3.16649, 1.46655, 1.63051, 3.30205, 1.16198},
          {2.99739, 1.10405, 3.75781, 1.69789, 2.66463, 2.54331, 1.13451},
      });

  double determinant = matrix.Determinant();

  EXPECT_NEAR(determinant, 24.111673073047285806, matrix.Epsilon());
}

TEST(MatrixDeterminant, ThrowIfMatrixNotSquare) {
  const s21::S21Matrix matrix(2, 3);

  EXPECT_THROW(matrix.Determinant(), std::logic_error);
}

TEST(MatrixDeterminant, ThrowIfMatrixIsEmpty) {
  const s21::S21Matrix empty_matrix;

  EXPECT_THROW(empty_matrix.Determinant(), std::logic_error);
}
