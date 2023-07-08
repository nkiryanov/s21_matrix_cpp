#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "matrix/s21_matrix_oop.h"

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
