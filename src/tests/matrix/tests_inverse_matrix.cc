#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(MatrixInverse, Regular3x3Case) {
  const s21::S21Matrix matrix(3, 3,
                              {
                                  {1., 2., 3.},
                                  {3., 2., 1.},
                                  {7., 5., 2.},
                              });
  const s21::S21Matrix expected_result(3, 3,
                                       {
                                           {-0.25, 2.75, -1.},
                                           {0.25, -4.75, 2.},
                                           {0.25, 2.25, -1.},
                                       });

  s21::S21Matrix inverse_matrix = matrix.InverseMatrix();

  EXPECT_TRUE(inverse_matrix == expected_result);
}

TEST(MatrixInverse, TestResultForMatrix4x4) {
  const s21::S21Matrix matrix(4, 4,
                              {
                                  {1.80377, 3.93870, 3.13429, 2.28155},
                                  {1.39307, 1.05586, 2.21357, 2.20440},
                                  {2.74323, 2.41325, 3.86805, 2.73013},
                                  {2.29065, 3.09765, 1.84139, 3.86339},
                              });
  const s21::S21Matrix expected_result(
      4, 4,
      {{-0.6892499107, -1.6362600080, 1.2909415507, 0.4284039249},
       {0.3588626362, -0.3777606089, -0.1150224313, 0.0848991764},
       {0.2706058939, 0.7498401502, -0.1659167199, -0.4704092234},
       {-0.0080477312, 0.9156520525, -0.5941100018, 0.1609714411}});

  s21::S21Matrix inverse_matrix = matrix.InverseMatrix();

  EXPECT_TRUE(inverse_matrix == expected_result);
}

TEST(MatrixInverse, ThrowIfDeterminantEqualsZero) {
  const s21::S21Matrix matrix(4, 4,
                              {
                                  {1.80377, 3.93870, 3.13429, 2.28155},
                                  {1.39307, 1.05586, 2.21357, 2.20440},
                                  {2.74323, 2.41325, 3.86805, 2.73013},
                                  {2.74323, 2.41325, 3.86805, 2.73013},
                              });

  EXPECT_THROW(matrix.InverseMatrix(), std::overflow_error);
}

TEST(MatrixInverse, ThrowIfMatrixEmpty) {
  const s21::S21Matrix empty_matrix;

  EXPECT_THROW(empty_matrix.InverseMatrix(), std::logic_error);
}

TEST(MatrixInverse, ThrowIfMatrixNotSquare) {
  const s21::S21Matrix matrix(1, 2);

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}
