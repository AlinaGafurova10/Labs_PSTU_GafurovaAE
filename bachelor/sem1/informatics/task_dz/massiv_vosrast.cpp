#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[7];
    bool f = false;
    int k = 0;

    for(int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    while((k < 6) && !f) // т.к будем проверять соседние элементы, то до 6 номера, чтобы
    // не выйти за пределы массива
    {
        if(a[k] < a[k+1])
        {
            k += 1;
        }
        else{
            f = true;
        }
    }

    if(f)
    {
        cout << "Массив не упорядочен по возрастанию" << endl;
    }
    else
    {
        cout << "Массив упорядочен по возрастанию" << endl; 
    }

    return 0;
}