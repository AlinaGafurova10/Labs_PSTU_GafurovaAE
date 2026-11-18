#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int** transposed = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
    }

    cout << "\nВведите элементы матрицы " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nТранспонированная матрица " << cols << "x" << rows << ":\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}