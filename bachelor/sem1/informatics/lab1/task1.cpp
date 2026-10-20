#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    float a_f = 1000.0, b_f = 0.0001;
    double a_d = 1000.0, b_d = 0.0001;
    
    float num1_f = pow(a_f - b_f, 3); // (a-b)^3_f = 999999616.0000000000
    float num2_f = pow(a_f, 3) - 3 * a_f * pow(b_f, 2); // a^3-3ab^2_f = 1000000000.0000000000 
    float chisl_f = num1_f - num2_f; // chisl_f = -384.0000000000 
    float znam_f = pow(b_f, 3) - 3 * pow(a_f, 2) * b_f;  // znam_f = -300.0000000000
    float rezult_f = chisl_f / znam_f; // rezult_f = 1.2799999714

    cout << "Type float" << endl;
    cout << fixed << setprecision(10);
    cout << "a = " << a_f << ", b = " << b_f << endl;
    cout << "(a-b)^3 = " << num1_f << endl;
    cout << "a^3 - 3ab^2 = " << num2_f << endl;
    cout << "Числитель = " << chisl_f << endl;
    cout << "Знаменатель = " << znam_f << endl;
    cout << "Результат (float) = " << rezult_f << endl;

    double num1_d = pow(a_d - b_d, 3); // (a-b)^3_d = 999999700.0000300407
    double num2_d = pow(a_d, 3) - 3 * a_d * pow(b_d, 2);  // a^3-3ab^2_d = 999999999.9999699593 
    double chisl_d = num1_d - num2_d; // chisl_d = -299.9999399185 
    double znam_d = pow(b_d, 3) - 3 * pow(a_d, 2) * b_d; // znam_d = -300.0000000000
    double rezult_d = chisl_d / znam_d;  // rezult_d = 0.9999997997

    cout << "\nType double" << endl;
    cout << "a = " << a_d << ", b = " << b_d << endl;
    cout << "(a-b)^3 = " << num1_d << endl;
    cout << "a^3 - 3ab^2 = " << num2_d << endl;
    cout << "Числитель = " << chisl_d << endl;
    cout << "Знаменатель = " << znam_d << endl;
    cout << "Результат (double) = " << rezult_d << endl;

    return 0;

    /**При использовании типа float результат вычисления
     составил 1.2799, что отличается от результата при 
     использовании типа double (0.99999979) на примерно 28%.  
     Различия обусловлены потерей точности при 
     вычитании близких чисел в формате float с ограниченной 
     мантиссой (24 бита, в то время как у double 53 бита, что обеспечивает большую точность). **/

}



































































