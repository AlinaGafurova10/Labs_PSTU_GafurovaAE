#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

// 1. Функция формирования двумерного динамического массива
int** createMatrix(int n, int m) {
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    return a;
}

// 2. Функция заполнения массива случайными числами
void fillMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 100; // Числа от 0 до 99
        }
    }
}

// 3. Функция печати массива
void printMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

// 4. Функция удаления строки с номером k
void deleteRow(int**& a, int& n, int m, int k) {
    // Освобождаем память удаляемой строки
    delete[] a[k];
    
    // Сдвигаем указатели на строки
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    
    // Создаем новый массив указателей размером на 1 меньше
    int** newMatr = new int*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        newMatr[i] = a[i];
    }
    
    // Удаляем старый массив указателей и присваиваем новый
    delete[] a;
    a = newMatr;
    
    // Уменьшаем количество строк
    n = n - 1;
}

// 5. Функция полного удаления массива
void deleteMatrix(int** a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int main() {
    setlocale(LC_ALL, ".65001");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n, m, k;
    
    // Ввод размеров массива
    cout << "Введите количество строк (N): ";
    cin >> n;
    cout << "Введите количество столбцов (M): ";
    cin >> m;

    // Формирование и заполнение массива
    int** a = createMatrix(n, m);
    fillMatrix(a, n, m);

    cout << "\nИсходный массив:\n";
    printMatrix(a, n, m);

    // Ввод номера строки для удаления
    cout << "\nВведите номер строки для удаления (от 0 до " << n - 1 << "): ";
    cin >> k;

    // Проверка корректности введенного индекса
    if (k < 0 || k >= n) {
        cout << "Ошибка: неверный номер строки!\n";
    } else {
        // Удаление строки
        deleteRow(a, n, m, k);
        
        cout << "\nМассив после удаления строки " << k << ":\n";
        printMatrix(a, n, m);
    }

    // Освобождение памяти
    deleteMatrix(a, n);

    return 0;
}