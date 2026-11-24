#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>

using namespace std;

const int N = 8;

// визуализация (спрашивается у пользователя)
string emptySym = ".";   // значок пустой клетки
string queenSym = "Q";   // значок ферзя
int cellW = 1;           // ширина клетки (для выравнивания)

// состояние поиска
vector<int>  colOfRow(N, -1);      // colOfRow[r] — столбец ферзя в строке r
vector<bool> usedCol(N, false);    // занятые столбцы
vector<bool> usedD1(2 * N, false); // главные диагонали: r + c
vector<bool> usedD2(2 * N, false); // побочные диагонали: r - c + N - 1

long long solutions = 0; // число готовых решений
long long nodes     = 0; // число посещённых узлов дерева поиска

bool canPlace(int r, int c) {
    return !usedCol[c] && !usedD1[r + c] && !usedD2[r - c + N - 1];
}

void printBoard() {
    ++solutions;
    cout << "\nРешение #" << solutions
         << "  (столбцы по строкам: ";
    for (int r = 0; r < N; ++r) cout << colOfRow[r] + 1 << ' ';
    cout << ")\n    ";
    for (int c = 0; c < N; ++c) cout << c + 1 << string(cellW, ' ');
    cout << "\n";
    for (int r = 0; r < N; ++r) {
        cout << "  " << r + 1 << " ";
        for (int c = 0; c < N; ++c) {
            string s = (colOfRow[r] == c) ? queenSym : emptySym;
            cout << s << string(cellW - (int)s.size(), ' ') << ' ';
        }
        cout << "\n";
    }
}

void solve(int r) {
    ++nodes;                       // зашли в узел дерева
    if (r == N) {                  // все 8 ферзей расставлены — решение готово
        printBoard();
        return;
    }
    for (int c = 0; c < N; ++c) {
        if (canPlace(r, c)) {
            colOfRow[r] = c;
            usedCol[c] = usedD1[r + c] = usedD2[r - c + N - 1] = true;
            solve(r + 1);          // спуск вниз по дереву
            // откат (backtrack)
            usedCol[c] = usedD1[r + c] = usedD2[r - c + N - 1] = false;
            colOfRow[r] = -1;
        }
    }
}

int main() {
    setlocale(LC_ALL, ".65001");
    cout << "=== Задача о восьми ферзях (8x8) ===\n\n";

    cout << "Введите значок пустого поля (например . или ~): ";
    getline(cin, emptySym);
    if (emptySym.empty()) emptySym = ".";
    cout << "Введите значок ферзя (например Q или X): ";
    getline(cin, queenSym);
    if (queenSym.empty()) queenSym = "Q";
    cellW = max((int)emptySym.size(), (int)queenSym.size());

    cout << "\nГотовые решения:\n";
    solve(0);

    cout << "\n=== Анализ результатов ===\n";
    cout << "Всего решений: " << solutions << "\n";
    cout << "Посещено узлов дерева поиска: " << nodes << "\n";
    return 0;
}