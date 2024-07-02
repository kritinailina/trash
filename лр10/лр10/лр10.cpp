#include <iostream>
using namespace std;

void print(int row, int col, int** arr) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void delet(int row, int** arr) {
    for (int i = 0; i < row; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int** create(int row, int col) {
    int** arr = new int* [row];
    for (int i = 0; i < row; ++i) {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = rand() % 100; // Случайное число от 0 до 99
        }
    }
    return arr;
}

int** delete_row(int row, int col, int** arr) {
    int rowToDelete;
    cout << "delete row: ";
    cin >> rowToDelete;
    if (rowToDelete >= 0 && rowToDelete < row) {
        // Создание нового массива с размером на 1 меньше
        int** newArray = new int* [row - 1];
        for (int i = 0, k = 0; i < row; ++i) {
            if (i != rowToDelete) {
                newArray[k] = arr[i];
                ++k;
            }
        }
        return newArray;
    }
    else {
        std::cout << "Некорректный индекс строки для удаления." << std::endl;
        return 0;
    }
}

int** delete_col(int row, int col, int** arr) {
    int colToDelete = 2;
    cout << "delete cols: ";
    cin >> colToDelete;
    if (colToDelete >= 0 && colToDelete < col) {
        int** newArray1 = new int* [row];
        for (int i = 0; i < row; ++i) {
            newArray1[i] = new int[col - 1];
            for (int j = 0, k = 0; j < col; ++j) {
                if (j != colToDelete) {
                    newArray1[i][k] = arr[i][j];
                    ++k;
                }
            }
        }
        return newArray1;
    }
    else {
        std::cout << "Некорректный индекс столбца для удаления." << std::endl;
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows;
    cout << "rows: ";
    cin >> rows;
    int cols;
    cout << "cols: ";
    cin >> cols;
    int** array = create(rows, cols);
    print(rows, cols, array);
    int** new_array = delete_row(rows, cols, array);
    --rows; print(rows, cols, new_array);
    int** new_array1 = delete_col(rows, cols, new_array);
    print(rows, --cols, new_array1);
    ..;
    delet(rows, new_array);
    delet(rows, new_array1);
}