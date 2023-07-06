#include <iostream>
#include <vector>

#include "s21_matrix_oop.h"

void PrintVector(std::vector<double>& vector) {
  std::cout << "Size: " << vector.size() << "\n";
  for (const auto& value : vector) {
    std::cout << value << " ";
  }

  std::cout << "\n";
}

int main() {
  std::vector<double> x(20, 3);

  x.resize(30);

  PrintVector(x);
}
