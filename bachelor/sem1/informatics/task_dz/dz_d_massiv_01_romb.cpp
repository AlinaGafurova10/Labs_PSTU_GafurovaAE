#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");

    int n;
    cout << "Введите размер квадратного массива (N): ";
    
    // Проверка корректности ввода
    if (!(cin >> n) || n <= 0) {
        cout << "Ошибка: размер должен быть целым числом больше 0." << endl;
        return 1;
    }

    // Выделение памяти под динамический двумерный массив
    int** matrix = new int*[n]; // Создаем массив указателей на строки
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n]; // Для каждой строки выделяем память под n элементов
    }

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Заполняем массив случайными значениями от 0 до 9
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10; 
        }
    }

    // Выводим исходный массив
    cout << "\n--- Исходный массив со случайными значениями ---\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << matrix[i][j]; 
        }
        cout << "\n";
    }

    // Выделяем самый большой ромб
    double center = (n - 1) / 2.0;
    double radius = n / 2.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Используем fabs для работы с числами с плавающей точкой
            double dist = fabs(i - center) + fabs(j - center);
            
            if (dist <= radius) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    // Выводим измененный массив
    cout << "\n--- Измененный массив (самый большой ромб из единиц) ---\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << matrix[i][j];
        }
        cout << "\n";
    }

    // Освобождение динамической памяти 
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i]; // Удаляем каждую строку
    }
    delete[] matrix; // Удаляем массив указателей

    return 0;
}







