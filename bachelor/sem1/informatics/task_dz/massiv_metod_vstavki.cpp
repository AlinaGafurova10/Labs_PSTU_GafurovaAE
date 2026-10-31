#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[7];
    //2 5 6 3 7 1 9

    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    // Алгоритм сортировки вставками
    cout << "Процесс сортировки: " << endl;
    for (int i = 1; i < 7; i++)
    {
        int y = a[i]; // Текущий элемент
        int j = i - 1;

        // Сдвигаем элементы отсортированной части, 
        // которые больше y, на одну позицию вправо
        while (j >= 0 && a[j] > y)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        
        // Вставляем y на его место
        a[j + 1] = y;

        //Вывод для наглядности
        for (int i = 0; i < 7; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

    }

    // Вывод отсортированного массива
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}