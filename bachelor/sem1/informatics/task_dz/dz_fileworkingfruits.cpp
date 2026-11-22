#include <iostream>   // Вывод в консоль
#include <fstream>    // Работа с файлами
#include <string>     // Тип string
#include <cstdio>     // Функция remove()
using namespace std;

int main()
{
    string row;

    ofstream temp;
    temp.open("File1.txt");                         
    temp << "apple\nbanana\napricot\ncherry\navocado\n"; 
    temp.close();                                 

    ifstream input;
    input.open("File1.txt");                         
    if (!input.is_open())                           
    {
        cout << "Не удалось открыть File1.txt\n";
        return 1;
    }

    ofstream output;
    output.open("File2.txt");                      
    if (!output.is_open())                          
    {
        cout << "Не удалось открыть File2.txt\n";
        return 1;
    }

    int count = 0;
    while (getline(input, row))                      
    {
        if (!row.empty() && row[0] == 'a')
        {
            output << row << "\n";                  
            count++;
        }
    }

    if (input.eof())                                 
        cout << "Файл прочитан полностью. "
             << "Строк на 'a': " << count << "\n";

    input.close();                                   
    output.close();                                  

    if (remove("File1.txt") == 0)                   
        cout << "File1.txt удалён\n";
    else
        cout << "Не удалось удалить File1.txt\n";

    ifstream check;
    check.open("File2.txt");                        
    cout << "Содержимое File2.txt:\n";
    while (getline(check, row))                      
        cout << row << "\n";
    check.close();                                  

    return 0;
}