#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");
    float a, b, c, x, D, x1, x2;

    cin >> a >> b >> c;
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl; 

    if (a == 0)
    {
        if (b != 0)
        {
            x = -c / b;
            cout << "0*x^2 + bx + c = 0 -> bx = -c -> x = -c / b -> x = " << x << endl; 
        }
        else 
        {
            if (c == 0)
                cout << "x - любое число" << endl; // 0 * x = 0

            else
                cout << "нет решений" << endl; // 0* x = (любое число кроме 0)
        }

    }
    else
    {
        D = pow(b, 2) - 4*a*c;

        if (D == 0)
        {
            x = -b / 2*a;
            cout << "Одно решение - x = " << x << endl;
        }
        else
        {
            if (D > 0)
            {
                x1 = (-b - sqrt(D)) / (2 * a);
                x2 = (-b + sqrt(D)) / (2 * a);
                cout << "Два решения - x1 = " << x1 << " x2 = " << x2 << endl;
            }
            else
            {
                cout << "нет решений" << endl;
            }
        }
    }
    

}