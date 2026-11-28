#include <iostream>
#include <clocale>

using namespace std;

struct Advertising {
    int zavka;
    int proc;
    int zp;
};

int main()
{
    setlocale(LC_ALL, ".65001");

    Advertising m;

    cout << "Введите сколько объявлений показано посетителям:" << endl;
    cin >> m.zavka;

    cout << "Введите сколько процентов посетителей нажали на объявление:" << endl;
    cin >> m.proc;

    cout << "Введите сколько вы заработали в среднем за каждое нажатие на объявления:" << endl;
    cin >> m.zp;

    cout << "Ваш доход:" << endl;
    cout << m.zavka * m.proc / 100 * m.zp << endl;
}