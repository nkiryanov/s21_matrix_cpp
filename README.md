[![Lint and test](https://github.com/nkiryanov/s21_matrix_cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/nkiryanov/s21_matrix_cpp/actions/workflows/ci.yml)

# s21_matrix_cpp

Работа с матрицами в CPP

### Как установить:
1. Для сборки нужен `cmake`
2. Т.к. проект учебный, то устанавливается в `{repository_root}/_install_dir`
    ```bash
    cd src
    make install
    ```
3. Так установятся:
    - статичная библиотека `s21_matrix_oop.a` в `_install_dir/lib`
    - публичный хэдер `s21_matrix_oop.h` в `_install_dir/include`
4. При использовании библиотеки используйте ключи для подключения хэдеров и библиотеки. Например:
    ```bash
    g++ -c --std=c++17 main.cc -I _install_dir/include/
    g++ --std=c++17 main.o -L _install_dir/lib/ -libs21_matrix_oop
    ```
 

### Класс матрицы:

```cpp
class s21::S21Matrix
```

### Конструкторы

| Готовность | Конструктор | Описание |
| - | ------ |------------------------------------------------------------------------------------|
| 🟢 | `S21Matrix()` | Базовый конструктор создающий матрицу с значениями по умолчанию |
| 🟢 | `S21Matrix(int rows, int cols)` | Параметризованный конструктор для задания количества строк и столбцов |
| 🟢 | `S21Matrix(int rows, int cols, std::initializer_list)` | Параметризованный конструктор для задания количества строк и столбцов + значение ячеек|
| 🟢 | `S21Matrix(const S21Matrix& other)` | Конструктор копирования |
| 🟢 | `S21Matrix(S21Matrix&& other)` | Конструктор перемещения |
| 🟢 | `~S21Matrix()` | Деструктор |

### Операции
| Готовность | Операция | Исключительные ситуации |
| - | ------ |------------------------------------------------------------------------------------|
| 🟢 | `+` | Сложение двух матриц | Разная размерность матриц |
| 🟢 | `-` | Вычитания двух матриц | Разные размерность матриц |
| 🟢 | `*` | Умножение двух матриц или матрицы на число | Количество столбцов первой матрицы не равно количеству строк второй |
| 🟢 | `==` | Сравнение двух матриц | — |
| 🟢 | `=` | Присваивание значения одной матрицы другой | — |
| 🟢 | `+=` | Сложение (прибавление матрицы к имеющейся) | Разная размерность матриц |
| 🟢 | `-=` | Вычитания (Вычитание матрицы от имеющейся) | Разная размерность матриц |
| 🟢 | `*=` | Умножение (на другую матрицу или на число) | Количество столбцов первой матрицы не равно количеству строк второй |
| 🟢 | `(int i, int j)` | Получение значения по индексу| Индекс за пределами значений|

### Функции
| Готовность| Операция | Описание | Исключительные ситуации |
| --- | ----------- | ----------- | ----------- |
| 🟢 | `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой |  |
| 🟢 | `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицы к текущей | различная размерность матриц |
| 🟢 | `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц |
| 🟢 | `void MulNumber(const double num)` | Умножает текущую матрицу на число |  |
| 🟢 | `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую | число столбцов первой матрицы не равно числу строк второй матрицы |
| 🟢 | `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее |  |
| 🟢 | `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной |
| 🟢 | `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы | матрица не является квадратной |
| 🟢 | `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу | определитель матрицы равен 0 |
