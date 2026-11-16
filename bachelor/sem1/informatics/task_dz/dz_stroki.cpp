#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    string word;
    setlocale(LC_ALL, ".65001");
    cout << "Введите слово: ";
    cin >> word;

    // Замена буквы на X
    if (word.size() > 5) {
        word[0] = 'X'; // Первую букву заменяем на X
    } else {
        word[word.size() - 1] = 'X'; // Последнюю букву заменяем на X
    }

    // Вывод слова справа налево
    cout << "Результат: ";
    for (int i = word.size() - 1; i >= 0; i--) {
        cout << word[i];
    }
    cout << endl;

    return 0;
}