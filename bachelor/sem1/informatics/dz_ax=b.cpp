#include <iostream>

using namespace std;

int main() 
{
    float a, b, x = 0;

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