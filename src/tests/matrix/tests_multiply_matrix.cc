#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(MulMatrix, EmptyCompatibleMatricesReturnEmptyMatrix) {
  s21::S21Matrix first(3, 2);
  s21::S21Matrix second(2, 3);

  first.MulMatrix(second);

  EXPECT_EQ(first.Rows(), 3);
  EXPECT_EQ(first.Columns(), 3);
  EXPECT_THAT(first.Data(), ElementsAre(0, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST(MulMatrix, MulAllRowsAndColumns) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  s21::S21Matrix second(2, 3, {1, 2, 3, 4, 5, 6});

  first.MulMatrix(second);

  EXPECT_EQ(first.Rows(), 3);
  EXPECT_EQ(first.Columns(), 3);
  EXPECT_THAT(first.Data(), ElementsAre(9, 12, 15, 19, 26, 33, 29, 40, 51));
}

TEST(MulMatrix, ThrowIfMatricesNotCompatibleForMul) {
  s21::S21Matrix first(1, 2);
  s21::S21Matrix second(3, 2);

  EXPECT_THROW(first.MulMatrix(second), std::invalid_argument);
}

TEST(MulMatrix, MulMatrixOperator) {
  const s21::S21Matrix first(2, 2, {1, 2, 3, 4});
  const s21::S21Matrix second(2, 1, {1, 2});
  const s21::S21Matrix expected(2, 1, {5, 11});

  s21::S21Matrix result = first * second;

  EXPECT_TRUE(result == expected);
}

TEST(MulMatrix, MulSelfMatrixOperator) {
  s21::S21Matrix matrix(2, 2, {1, 2, 3, 4});
  const s21::S21Matrix second(2, 1, {1, 2});
  const s21::S21Matrix expected(2, 1, {5, 11});

  matrix *= second;

  EXPECT_TRUE(matrix == expected);
}
