#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

// Функция выделения динамического массива и заполнения его случайными числами
int* createArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 - 50; // числа от -50 до 49 (чтобы были и отрицательные)
    }
    return arr;
}

// Функция копирования массива (чтобы сохранить исходные значения)
int* copyArray(const int* src, int n) {
    int* copy = new int[n];
    for (int i = 0; i < n; ++i) {
        copy[i] = src[i];
    }
    return copy;
}

// Функция вывода массива
void printArray(const int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

// Основная функция преобразования массива
void transformArray(int* arr, int n) {
    // Создаём копию, чтобы использовать исходные значения соседей
    int* orig = copyArray(arr, n);

    for (int i = 0; i < n; ++i) {
        if (orig[i] % 2 == 0) {
            if (i == 0 || i == n - 1) {
                arr[i] = 0;
            }
            else {
                arr[i] = orig[i - 1] + orig[i + 1];
            }
        }
    }

    delete[] orig; 
}

int main() {
    setlocale(LC_ALL, ".65001");
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер должен быть больше нуля!\n";
        return 1;
    }

    // Создаём и заполняем массив
    int* arr = createArray(n);

    cout << "\nИсходный массив:\n";
    printArray(arr, n);

    // Преобразуем массив
    transformArray(arr, n);

    cout << "\nПреобразованный массив:\n";
    printArray(arr, n);

    delete[] arr;

    return 0;
}