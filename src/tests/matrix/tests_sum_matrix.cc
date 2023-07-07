#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

using ::testing::ElementsAre;

TEST(SumMatrix, SummingEmptyMatrixReturnEmptyMatrix) {
  s21::S21Matrix first_empty;
  const s21::S21Matrix second_empty;

  first_empty.SumMatrix(second_empty);

  EXPECT_TRUE(first_empty == second_empty);
}

TEST(SumMatrix, SumMatrixActuallySumMatrices) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(3, 2, {1, 2, 3, 4, 5, 6});

  first.SumMatrix(second);

  EXPECT_TRUE(first == s21::S21Matrix(3, 2, {2, 4, 6, 8, 10, 12}));
}

TEST(SumMatrix, ThrowIfRowsNotMatch) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(1, 2, {1, 2});

  EXPECT_THROW(first.SumMatrix(second), std::invalid_argument);
}

TEST(SumMatrix, ThrowIfColumnsNotMatch) {
  s21::S21Matrix first(3, 2, {1, 2, 3, 4, 5, 6});
  const s21::S21Matrix second(3, 1, {1, 2, 3});

  EXPECT_THROW(first.SumMatrix(second), std::invalid_argument);
}

TEST(SumMatrix, SumMatrixOperatorWorksOk) {
  const s21::S21Matrix first(1, 2, {1, 2});
  const s21::S21Matrix second(1, 2, {1, 2});
  const s21::S21Matrix expected(1, 2, {2, 4});

  s21::S21Matrix result = first + second;

  EXPECT_TRUE(result == expected);
}

TEST(SumMatrix, SumSelfMatrixOperatorWorksOk) {
  s21::S21Matrix matrix(1, 2, {1, 2});
  const s21::S21Matrix second(1, 2, {1, 2});
  const s21::S21Matrix expected(1, 2, {2, 4});

  matrix += second;

  EXPECT_TRUE(matrix == expected);
}
