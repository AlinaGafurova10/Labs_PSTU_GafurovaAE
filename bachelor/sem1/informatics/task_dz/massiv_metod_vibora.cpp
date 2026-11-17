#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[100]; //2 5 6 3 7 1 9
    int n;

    cout <<"Введите размер массива: "<<endl;
    cin >> n;

    cout << "Введите" << n << "чисел" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Алгоритм сортировки методом выбора
    cout << "Процесс сортировки: " << endl;
    for(int i = 1; i < n; i++)
    {
        int min = i; 

        // находим минимальный элемент неотсортированной части
        for(int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        // меняем местами минимальный и текущий элемент
        int k = a[i];
        a[i] = a[min];
        a[min] = k;

        // выводим для наглядности
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Вывод отсортированного массива
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}