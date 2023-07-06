#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MatrixOperators, GetItemValueByIndexes) {
  s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  EXPECT_EQ(matrix(0, 0), 1);
  EXPECT_EQ(matrix(0, 2), 3);
  EXPECT_EQ(matrix(1, 0), 4);
  EXPECT_EQ(matrix(1, 2), 6);
}

TEST(MatrixOperators, GetItemValueByIndexesForConst) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  EXPECT_EQ(matrix(0, 0), 1);
  EXPECT_EQ(matrix(0, 2), 3);
  EXPECT_EQ(matrix(1, 0), 4);
  EXPECT_EQ(matrix(1, 2), 6);
}

TEST(MatrixOperators, ThrowGetByIndexIfIndexOutOfRange) {
  const s21::S21Matrix matrix(2, 3, {1, 2, 3, 4, 5, 6});

  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix(3, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, -1), std::out_of_range);
  EXPECT_THROW(matrix(0, 3), std::out_of_range);
}

TEST(MatrixOperators, ThrowGetByIndexIfEmptyMatrix) {
  const s21::S21Matrix matrix;

  EXPECT_THROW(matrix(0, 0), std::out_of_range);
}

TEST(MatrixOperators, EqOperatorReturnTrueEqualMatrices) {
  const s21::S21Matrix first(3, 1, {1.00000001, 2, 3});
  const s21::S21Matrix second(3, 1, {1.00000005, 2, 3});

  EXPECT_TRUE(first == second);
}

TEST(MatrixOperators, EqOperatorReturnFalseEqualMatrices) {
  const s21::S21Matrix first(1, 1, {1});
  const s21::S21Matrix second(1, 1, {10});

  EXPECT_FALSE(first == second);
}

TEST(MatrixOperators, MulMatrixOperator) {
  const s21::S21Matrix first(2, 2, {1, 2, 3, 4});
  const s21::S21Matrix second(2, 1, {1, 2});

  s21::S21Matrix result = first * second;

  EXPECT_EQ(result.Rows(), 2);
  EXPECT_EQ(result.Columns(), 1);
  EXPECT_THAT(result.Data(), ElementsAre(5, 11));
}

TEST(MatrixOperators, MulSelfMatrixOperator) {
  s21::S21Matrix matrix(2, 2, {1, 2, 3, 4});
  const s21::S21Matrix second(2, 1, {1, 2});

  matrix *= second;

  EXPECT_EQ(matrix.Rows(), 2);
  EXPECT_EQ(matrix.Columns(), 1);
  EXPECT_THAT(matrix.Data(), ElementsAre(5, 11));
}
