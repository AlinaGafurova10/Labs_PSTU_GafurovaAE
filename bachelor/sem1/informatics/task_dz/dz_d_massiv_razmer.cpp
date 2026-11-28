#include <iostream>
#include <cstdlib>   
#include <ctime>
#include <clocale>

using namespace std;

// Функция для увеличения вместимости массива
void reallocate(int*& arr, int& capacity, int size) {
    int new_capacity = (capacity == 0) ? 1 : capacity * 2;
    int* new_arr = new int[new_capacity];

    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }

    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

// Функция добавления N случайных элементов
void addElements(int*& arr, int& size, int& capacity, int count) {
    for (int i = 0; i < count; ++i) {
        if (size == capacity) {
            reallocate(arr, capacity, size);
        }
        arr[size] = rand() % 100; // случайное число от 0 до 99
        size++;
    }
}

// Функция удаления N элементов с конца
void removeElements(int*& arr, int& size, int& capacity, int count) {
    if (count > size) {
        cout << "Нельзя удалить " << count << " элементов, в массиве только " << size << ".\n";
        cout << "Удаляю все " << size << " элементов.\n";
        count = size;
    }

    size -= count;

    // Оптимизация: если элементов стало в 4 раза меньше, чем выделено — уменьшаем память
    if (size > 0 && size <= capacity / 4) {
        int new_capacity = capacity / 2;
        int* new_arr = new int[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    } 
    else if (size == 0) {
        delete[] arr;
        arr = nullptr;
        capacity = 0;
    }
}

// Функция вывода массива
void printArray(const int* arr, int size, int capacity) {
    cout << "Массив: [ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    cout << "Размер (size): " << size << " | Вместимость (capacity): " << capacity << "\n\n";
}

int main() {
    setlocale(LC_ALL, ".65001");
    srand(static_cast<unsigned int>(time(nullptr)));

    int initialSize;
    cout << "Введите начальный размер массива: ";
    cin >> initialSize;

    // Выделяем начальную память
    int capacity = (initialSize > 0) ? initialSize : 1;
    int size = 0;
    int* arr = new int[capacity];

    // Заполняем начальный массив случайными числами
    for (int i = 0; i < initialSize; ++i) {
        arr[size] = rand() % 100;
        size++;
    }

    cout << "\n--- Начальный массив ---\n";
    printArray(arr, size, capacity);

    // Спрашиваем у пользователя, что делать
    int action;
    cout << "Что сделать с массивом?\n";
    cout << "1 — добавить элементы\n";
    cout << "2 — удалить элементы\n";
    cout << "Ваш выбор: ";
    cin >> action;

    int count;
    cout << "Сколько элементов: ";
    cin >> count;

    if (action == 1) {
        cout << "\n--- Добавляю " << count << " случайных элементов ---\n";
        addElements(arr, size, capacity, count);
    } 
    else if (action == 2) {
        cout << "\n--- Удаляю " << count << " элементов ---\n";
        removeElements(arr, size, capacity, count);
    } 
    else {
        cout << "Неверный выбор!\n";
    }

    cout << "\n--- Итоговый массив ---\n";
    printArray(arr, size, capacity);

    // Освобождаем память в конце программы
    delete[] arr;

    return 0;
}