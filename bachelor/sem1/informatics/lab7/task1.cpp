#include <iostream>
#include <clocale>
#include <complex> 

using namespace std;

//Перегруженная функция для вычитания чисел типа float
float subtract(float a, float b) {
    return a - b;
}

//Перегруженная функция для вычитания чисел типа double
double subtract(double a, double b) {
    return a - b;
}

//Перегруженная функция для вычитания комплексных чисел
complex<double> subtract(complex<double> a, complex<double> b) {
    return a - b; 
}

int main() {
    setlocale(LC_ALL, ".65001");

    //Ввод и вычитание вещественных чисел (float)
    float f1, f2;
    cout << "1. Введите два числа типа float: ";
    cin >> f1 >> f2;
    cout << "   Результат (float): " << f1 << " - " << f2 
              << " = " << subtract(f1, f2) << "\n\n";
    
    //Ввод и вычитание вещественных чисел (double)
    double d1, d2;
    cout << "2. Введите два числа типа double: ";
    cin >> d1 >> d2;
    cout << "   Результат (double): " << d1 << " - " << d2 
              << " = " << subtract(d1, d2) << "\n\n";
    
    //Ввод и вычитание комплексных чисел
    double real1, imag1, real2, imag2;
    cout << "3. Введите первое комплексное число:\n";
    cout << "   Действительная часть: "; cin >> real1;
    cout << "   Мнимая часть: "; cin >> imag1;
    
    cout << "   Введите второе комплексное число:\n";
    cout << "   Действительная часть: "; cin >> real2;
    cout << "   Мнимая часть: "; cin >> imag2;

    // Создаем объекты стандартного класса complex
    complex<double> c1(real1, imag1);
    complex<double> c2(real2, imag2);
    
    complex<double> c_res = subtract(c1, c2);
    
    cout << "   Результат (complex): (" << c1.real() << " + " << c1.imag() << "i) - (" 
              << c2.real() << " + " << c2.imag() << "i) = (" 
              << c_res.real() << " + " << c_res.imag() << "i)\n";

    return 0;
}