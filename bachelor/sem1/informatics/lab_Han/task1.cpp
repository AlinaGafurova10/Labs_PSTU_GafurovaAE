#include <iostream>
#include <clocale>

using namespace std;

void han(int n, int start, int point, int temp)
{
    if (n <= 0)
        return;

    han(n - 1, start, temp, point);
    cout << start << " => " << point << endl;
    han(n - 1, temp, point, start);
}

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    han(n, 1, 3, 2);
    
    return 0;
}