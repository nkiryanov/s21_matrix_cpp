#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixConstructors, SquareMatrixConstructorCreateMatrix) {
    s21::S21Matrix matrix(5);

    EXPECT_EQ(matrix.Rows(), 5);
    EXPECT_EQ(matrix.Columns(), 5);
}
