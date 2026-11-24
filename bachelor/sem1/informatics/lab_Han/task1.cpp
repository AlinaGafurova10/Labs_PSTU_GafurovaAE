#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int rod[3][10]; // диски на каждом стержне (снизу вверх)
int cnt[3]; // сколько дисков на каждом стержне
int N; // всего колец

// Нарисовать текущее состояние башни
void draw()
{
    // "очистка" экрана: много пустых строк
    for (int i = 0; i < 30; i++) cout << "\n";

    int W = 2 * N + 1; // ширина одного стержня в символах

    // Ряды сверху вниз: row = N-1 (верх) ... 0 (низ)
    for (int row = N - 1; row >= 0; row--) {
        for (int s = 0; s < 3; s++) {
            if (row < cnt[s]) {
                // в этом ряду есть диск
                int d = rod[s][row]; // размер диска
                int w = 2 * d - 1; // ширина в звёздочках
                int pad = (W - w) / 2; // отступ слева/справа
                cout << string(pad, ' ') << string(w, '*') << string(pad, ' ');
            } else {
                // диска нет — рисуем только стержень
                cout << string(N, ' ') << "|" << string(N, ' ');
            }
            cout << "   ";   // отступ между стержнями
        }
        cout << "\n";
    }

    // Основание под каждым стержнем
    for (int s = 0; s < 3; s++)
        cout << string(W, '-') << "   ";
    cout << "\n";

    // Номера стержней: 1 2 3
    for (int s = 0; s < 3; s++)
        cout << string(N, ' ') << s + 1 << string(N, ' ') << "   ";
    cout << "\n";
}

// Переложить верхний диск со стержня a на стержень c (a, c = 1..3)
void moveDisk(int a, int c)
{
    int from = a - 1; // перевод в индексы 0..2
    int to = c - 1;

    int d = rod[from][cnt[from] - 1]; // берём верхний диск
    cnt[from]--; // снимаем его
    rod[to][cnt[to]] = d; // кладём сверху на другой
    cnt[to]++;

    draw(); // показать результат
    cout << "Enter..."; // пауза
    cin.get();
}

void han(int n, int a, int c, int b)
{
    if (n > 0) {
        han(n - 1, a, b, c); // n-1 дисков: с a на b
        moveDisk(a, c); // самый большой: с a на c
        han(n - 1, b, c, a); // n-1 дисков: с b на c
    }
}

int main()
{
    setlocale(LC_ALL, ".65001");

    cout << "Введите количество колец: ";
    cin >> N;
    cin.ignore(); // убрать '\n' после ввода числа

    // Кладём все диски на первый стержень: снизу большой, сверху маленький
    for (int i = 0; i < N; i++)
        rod[0][i] = N - i;
    cnt[0] = N; // остальные стержни уже пусты (0)

    draw();
    cout << "Enter...";
    cin.get();

    han(N, 1, 3, 2);
    return 0;
}