#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

class MinorMatrixTest : public ::testing::Test {
 protected:
  const s21::S21Matrix matrix4x4;

  MinorMatrixTest()
      : matrix4x4(4, 4,
                  {
                      {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16},
                  }) {}
};

TEST_F(MinorMatrixTest, MinorMatrixByFirstRowAndFirstColumnCreated) {
  s21::S21Matrix minor = matrix4x4.MinorMatrix(0, 0);

  EXPECT_EQ(minor.GetRows(), 3);
  EXPECT_EQ(minor.GetColumns(), 3);
  EXPECT_TRUE(minor == s21::S21Matrix(3, 3,
                                      {
                                          {6, 7, 8},
                                          {10, 11, 12},
                                          {14, 15, 16},
                                      }));
}

TEST_F(MinorMatrixTest, MinorMatrixByMiddleRowAndColumnCreated) {
  s21::S21Matrix minor = matrix4x4.MinorMatrix(2, 1);

  EXPECT_EQ(minor.GetRows(), 3);
  EXPECT_EQ(minor.GetColumns(), 3);
  EXPECT_TRUE(minor == s21::S21Matrix(3, 3,
                                      {
                                          {1, 3, 4},
                                          {5, 7, 8},
                                          {13, 15, 16},
                                      }));
}

TEST_F(MinorMatrixTest, ThrowIfMatrixNotSquare) {
  s21::S21Matrix matrix(3, 4);

  EXPECT_THROW(matrix.MinorMatrix(0, 0), std::logic_error);
}

TEST_F(MinorMatrixTest, ThrowIfMatrixEmpty) {
  s21::S21Matrix matrix;

  EXPECT_THROW(matrix.MinorMatrix(0, 0), std::logic_error);
}

TEST_F(MinorMatrixTest, ThrowIfMatrixSizeOne) {
  s21::S21Matrix matrix(1);

  EXPECT_THROW(matrix.MinorMatrix(0, 0), std::logic_error);
}

TEST_F(MinorMatrixTest, ThrowIfRowsOutOfRange) {
  EXPECT_THROW(matrix4x4.MinorMatrix(4, 0), std::range_error);
}

TEST_F(MinorMatrixTest, ThrowIfColumnsOutOfRange) {
  EXPECT_THROW(matrix4x4.MinorMatrix(0, 4), std::range_error);
}
