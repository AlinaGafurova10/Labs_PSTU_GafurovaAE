#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[100];
    int n;

    cout <<"Введите размер массива: "<<endl;
    cin >> n;

    cout << "Введите" << n << "чисел" << endl;
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    // Алгоритм сортировки вставками
    cout << "Процесс сортировки: " << endl;
    for (int i = 1; i < n; i++)
    {
        int y = a[i]; // Текущий элемент
        int j = i - 1;
        bool f = false;

        // Сдвигаем элементы отсортированной части, 
        // которые больше y, на одну позицию вправо
        while (j >= 0 && !f)
        {
            if(a[j] > y)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                f = true;
        }
        
        // Вставляем y на его место
        a[j + 1] = y;

        //Вывод для наглядности
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