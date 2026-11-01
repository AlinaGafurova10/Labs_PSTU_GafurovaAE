#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 100;
    int M[MAX_SIZE];
    int n;

    // 1. Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Ввод размера массива
    cout << "Введите размер массива (1-" << MAX_SIZE << "): ";
    cin >> n;

    // 1. Формирование массива случайными числами (от 0 до 49)
    for (int i = 0; i < n; ++i) {
        M[i] = rand() % 50;
    }

    // 2. Распечатка исходного массива
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << M[i] << " ";
    }
    cout << endl;

    // 3. Удаление элемента с заданным номером
    int del_pos;
    cout << "\nВведите номер элемента для удаления (1-" << n << "): ";
    cin >> del_pos;
    
    if (del_pos >= 1 && del_pos <= n) {
        int idx = del_pos - 1; // Переход к 0-_based индексу
        for (int i = idx; i < n - 1; ++i) {
            M[i] = M[i + 1]; // Сдвиг элементов влево
        }
        n--; // Уменьшение реальной длины массива
        cout << "Массив после удаления элемента:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << M[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Некорректный номер элемента. Удаление не выполнено." << endl;
    }

    // 4. Добавление после первого четного элемента
    int first_even_idx = -1;
    bool f = false;
    int k = 0;
    while((k < n) && !f) {
        if (M[k] % 2 == 0) {
            first_even_idx = k;
            f = true;
        }
        k+=1;
    }

    if (first_even_idx != -1) {
        if (n < MAX_SIZE) {
            int value_to_add = M[first_even_idx] + 2; // M[I-1] + 2, где I-1 = first_even_idx
            
            // Сдвиг элементов вправо, начиная с конца, чтобы освободить место
            for (int i = n; i > first_even_idx + 1; --i) {
                M[i] = M[i - 1];
            }
            
            M[first_even_idx + 1] = value_to_add;
            n++; // Увеличение реальной длины массива
            
            cout << "\nЭлемент " << value_to_add << " добавлен после первого четного элемента (" 
                 << M[first_even_idx] << ")." << endl;
        } else {
            cout << "\nНевозможно добавить элемент: достигнут максимальный размер массива." << endl;
        }
    } else {
        cout << "\nВ массиве нет четных элементов. Добавление не выполнено." << endl;
    }

    // 5. Распечатка итогового массива
    cout << "\nИтоговый массив:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << M[i] << " ";
    }
    cout << endl;

    return 0;
}