#include <iostream>
#include <clocale>
#include <cstring>
#include <cctype> 

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    char s[256];
    char res[256];
    int j = 0;

    cin.getline(s, 256);

    //Первый проход: извлекаем только буквы
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isalpha(s[i])) 
        {
            res[j++] = s[i];
        }
    }

    //Второй проход: извлекаем только цифры
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
        {
            res[j++] = s[i];
        }
    }

    res[j] = '\0';

    cout << "Результат:\n" << res << endl;

    return 0;
}