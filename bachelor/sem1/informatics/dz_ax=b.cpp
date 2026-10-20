#include <iostream>
#include <locale>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    float a, b, x;

    cin >> a >> b;

    if (a != 0)
    {
        x = b / a;
        cout << "ax = b -> x = " << x << endl; 
    }
    else 
    {
        if (b == 0)
        {
            cout << "x - любое число" << endl; // 0 * x = 0
        }
        else 
        {
            cout << "нет решений" << endl; // 0 * x = (любое число кроме 0)
        }
        
    }

}