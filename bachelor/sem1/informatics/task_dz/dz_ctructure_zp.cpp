#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Для красивого вывода таблицы

using namespace std;

// Структура для хранения данных о работнике
struct Employee {
    string fullName;   // ФИО работника
    int daysWorked;         // Отработанные дни
    double dailyPay;        // Оплата за день
    double bonus;           // Премия
};

// Функция для расчета заработной платы
double calculateSalary(const Employee& emp) {
    return (emp.daysWorked * emp.dailyPay) + emp.bonus;
}

int main() {
    // Устанавливаем локаль для корректного отображения кириллицы (для Windows)
    setlocale(LC_ALL, "Russian");

    int count;
    cout << "Введите количество работников для расчета: ";
    cin >> count;

    // Создаем вектор для хранения данных о работниках
    vector<Employee> employees(count);

    // Ввод данных по каждому работнику
    for (int i = 0; i < count; ++i) {
        cout << "\n--- Данные для работника " << i + 1 << " ---\n";
        
        // Очищаем буфер ввода перед чтением строки
        cin.ignore(); 
        
        cout << "Введите ФИО работника: ";
        getline(cin, employees[i].fullName);
        
        cout << "Введите количество отработанных дней: ";
        cin >> employees[i].daysWorked;
        
        cout << "Введите оплату за один день: ";
        cin >> employees[i].dailyPay;
        
        cout << "Введите размер премии: ";
        cin >> employees[i].bonus;
    }

    // Вывод результатов расчета
    cout << "\n========================================\n";
    cout << "         РЕЗУЛЬТАТЫ РАСЧЕТА\n";
    cout << "========================================\n";
    
    // Настройка ширины столбцов для красивого вывода
    cout << left << setw(25) << "ФИО" 
              << right << setw(10) << "Дни" 
              << setw(12) << "Оплата/день" 
              << setw(10) << "Премия" 
              << setw(15) << "Итого (ЗП)" << "\n";
    cout << "--------------------------------------------------------------------\n";

    for (int i = 0; i < count; ++i) {
        double salary = calculateSalary(employees[i]);
        
        cout << left << setw(25) << employees[i].fullName 
                  << right << setw(10) << employees[i].daysWorked 
                  << setw(12) << fixed << setprecision(2) << employees[i].dailyPay 
                  << setw(10) << employees[i].bonus 
                  << setw(15) << salary << " руб.\n";
    }
    cout << "========================================\n";

    return 0;
}