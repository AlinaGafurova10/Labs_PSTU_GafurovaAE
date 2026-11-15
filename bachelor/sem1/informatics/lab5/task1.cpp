#include <iostream>
#include <clocale>

using namespace std;

void findSedlPoint(int n, int m, int a[][100])
{
    int minRow[100];
    int maxRow[100];
    int minCol[100];
    int maxCol[100];

    //Находим максимальные и минимальные элементы для каждой строки
    for(int i = 0; i < n; i++)
    {
        minRow[i] = a[i][0];
        maxRow[i] = a[i][0];
        for(int j = 1; j < m; j++)
        {
            if(a[i][j] < minRow[i])
                minRow[i] = a[i][j];
            if(a[i][j] > maxRow[i])
                maxRow[i] = a[i][j];
        }
    }

    //Находим максимальные и минимальные элементы для каждого столбца
    for(int j = 0; j < m; j++)
    {
        minCol[j] = a[0][j];
        maxCol[j] = a[0][j];
        for(int i = 1; i < n; i++)
        {
            if(a[i][j] < minCol[j])
                minCol[j] = a[i][j];
            if(a[i][j] > maxCol[j])
                maxCol[j] = a[i][j];
        }
    }

    //Находим седловые точки
    bool f = false;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bool cond1 = ((a[i][j] == minRow[i]) && (a[i][j] == maxCol[j]));
            bool cond2 = ((a[i][j] == maxRow[i]) && (a[i][j] == minCol[j]));

            if(cond1 || cond2)
            {
                cout << "Элемент: " << a[i][j] << " является ";
                if(cond1)
                {
                cout << "минимальным в строке " << i << ", максимальным в столбце " << j << endl;
                }
                else
                {
                cout << "максимальным в строке " << i << ", минимальным в столбце " << j << endl;
                }
                f = true;
            }
        }
    }

    if(!f)
    {
    cout << "Не найдено седловых точек" << endl;
    }
    
}

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[100][100];
    int n, m;
    
    cout << "Введите количество строк:" << endl;
    cin >> n;

    cout << "Введите количество столбцов:" << endl;
    cin >> m;

    cout << "Введите матрицу:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    //Вызываем функцию передавая массив а
    findSedlPoint(n, m, a);

    return 0;

}