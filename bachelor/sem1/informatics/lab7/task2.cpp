#include <iostream>
#include <cstdarg>  

using namespace std;

// Функция поиска минимума среди целых чисел
// Первый параметр (count) задаёт количество последующих аргументов
int min(int count, ...) {
    va_list args;             // Переменная для хранения списка аргументов
    va_start(args, count);    // Инициализация списка
    
    // Инициализируем минимальное значение первым аргументом
    int current_min = va_arg(args, int);
    
    // Проходим по оставшимся (count - 1) аргументам
    for (int i = 1; i < count; ++i) {
        int val = va_arg(args, int); // Извлекаем следующий аргумент типа int
        if (val < current_min) {
            current_min = val;       // Обновляем минимум
        }
    }
    
    va_end(args); // Завершаем работу со списком аргументов
    return current_min;
}

int main() {
    setlocale(LC_ALL, ".65001");

    int a1, a2, a3, a4, a5;
    int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11,c12;
    
    cout << "Введите 5 чисел для поиска минимума: ";
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    cout << "Введите 10 чисел для поиска минимума: ";
    cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6 >> b7 >> b8 >> b9 >> b10;

    cout << "Введите 12 чисел для поиска минимума: ";
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9 >> c10 >> c11 >> c12;
    
    cout << "Минимум среди 5 введеных чисел: " << min(5, a1, a2, a3, a4, a5) << endl;
    cout << "Минимум среди 10 введеных чисел: " << min(10, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10) << endl;
    cout << "Минимум среди 12 введеных чисел: " << min(12, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11,c12) << endl;
    
    return 0;
}