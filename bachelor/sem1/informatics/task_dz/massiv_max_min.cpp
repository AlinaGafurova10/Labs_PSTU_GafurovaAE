#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[7];

    for(int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    int max_val = a[0];
    int max_index = 0;
    int max_count = 1; 

    int min_val = a[0];
    int min_index = 0;
    int min_count = 1; 

    for(int i = 1; i < 7; i++)
    {
        // Поиск максимума
        if (a[i] > max_val) 
        {
            max_val = a[i];
            max_index = i;
            max_count = 1; // сбросили счётчик — нашли новый максимум
        }
        else if (a[i] == max_val) 
        {
            max_count++; // такой же максимум — увеличиваем счётчик
        }

        // Поиск минимума
        if (a[i] < min_val) 
        {
            min_val = a[i];
            min_index = i;
            min_count = 1;
        }
        else if (a[i] == min_val) 
        {
            min_count++;
        }
    }

    // Вывод результата
    cout << "max = " << max_val 
         << "; Индекс max: " << max_index 
         << "; Номер max: " << max_index + 1 
         << "; Количество max: " << max_count << endl;

    cout << "min = " << min_val 
         << "; Индекс min: " << min_index 
         << "; Номер min: " << min_index + 1 
         << "; Количество min: " << min_count << endl;

    return 0;
}