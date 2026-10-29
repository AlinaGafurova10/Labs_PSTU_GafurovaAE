#include <iostream>
#include <clocale>
#include <iomanip> 
#include <string>  

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    
    int sm;
    int a[2][3];
    int s_a[2];

    for(int i = 0; i < 2; i++)
    {
        sm = 0;
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            sm += a[i][j];
        }
        s_a[i] = sm;
    }

    int size_symb = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int curr_leng = to_string(a[i][j]).length();
            if (curr_leng > size_symb)
            {
                size_symb = curr_leng;
            }
        }
    }

    cout << "Массив" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            // setw(size_symb) резервирует ровно столько символов, 
            // сколько нужно для самого длинного числа, выравнивая по правому краю
            cout << setw(size_symb + 2) << a[i][j] << "  "; 
        }
        cout << endl;
    }
    // Вывод сумм 
    cout << "Сумма в первой строке: " << s_a[0] << endl; // -293
    cout << "Сумма во второй строке: " << s_a[1] << endl; // 6939

    return 0;

    /*
    2 -300 5
    -67 6 7000
    */
}