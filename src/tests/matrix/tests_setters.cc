#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixSetter, RowsIncreasedCorrectlyForEmptyMatrix) {
  s21::S21Matrix matrix;  // empty matrix

  matrix.SetRows(3);

  EXPECT_EQ(matrix.Rows(), 3);
  EXPECT_EQ(matrix.Columns(), 0);
  EXPECT_EQ(matrix.Data().size(), 0);
}

TEST(MatrixSetter, ColumnsIncreasedCorrectlyForEmptyMatrix) {
  s21::S21Matrix matrix;  // empty matrix

  matrix.SetColumns(3);

  EXPECT_EQ(matrix.Rows(), 0);
  EXPECT_EQ(matrix.Columns(), 3);
  EXPECT_EQ(matrix.Data().size(), 0);
}

TEST(MatrixSetter, NotEmptyMatrixIncreasedOkByRows) {
  s21::S21Matrix matrix(1, 1, {10});

  matrix.SetRows(2);

  EXPECT_EQ(matrix.Rows(), 2);
  EXPECT_EQ(matrix.Columns(), 1);
  EXPECT_EQ(matrix(0, 0), 10);
  EXPECT_EQ(matrix(1, 0), 0);
}

TEST(MatrixSetter, NotEmptyMatrixIncreasedOkByColumns) {
  s21::S21Matrix matrix(1, 1, {10});

  matrix.SetColumns(2);

  EXPECT_EQ(matrix.Rows(), 1);
  EXPECT_EQ(matrix.Columns(), 2);
  EXPECT_EQ(matrix(0, 0), 10);
  EXPECT_EQ(matrix(0, 1), 0);
}

TEST(MatrixSetter, NotEmptyMatrixDecreasedOkByRows) {
  s21::S21Matrix matrix(2, 2, {1, 2, 3, 4});

  matrix.SetRows(1);

  EXPECT_EQ(matrix.Rows(), 1);
  EXPECT_EQ(matrix.Columns(), 2);
  EXPECT_EQ(matrix(0, 0), 1);
  EXPECT_EQ(matrix(0, 1), 2);
}

TEST(MatrixSetter, NotEmptyMatrixDecreasedOkByColumns) {
  s21::S21Matrix matrix(2, 2, {1, 2, 3, 4});

  matrix.SetColumns(1);

  EXPECT_EQ(matrix.Rows(), 2);
  EXPECT_EQ(matrix.Columns(), 1);
  EXPECT_EQ(matrix(0, 0), 1);
  EXPECT_EQ(matrix(1, 0), 3);
}

TEST(MatrixSetter, ThrowIfRowsOrColumnsNegative) {
  s21::S21Matrix matrix(1);

  EXPECT_THROW(matrix.SetRows(-1), std::length_error);
  EXPECT_THROW(matrix.SetColumns(-1), std::length_error);
}
