#include <iostream>
#include <cstdio>
#include <clocale>
#include <cstring>
#include <cstdlib>

using namespace std;

// Структура данных по варианту 6
struct Schoolchild {
    char surname[50];
    char name[50];
    char patronymic[50];
    char className[10];
    char phone[20];
    int grades[4]; // 0:мат, 1:физ, 2:рус, 3:лит
};

// Вспомогательная функция поиска двойки
bool hasGradeTwo(const Schoolchild& s) {
    for (int i = 0; i < 4; i++) {
        if (s.grades[i] == 2) return true;
    }
    return false;
}

void createFile(const char* filename) {
    FILE* f = fopen(filename, "wb"); // "wb" = write binary. Создает новый файл или очищает старый.
    if (!f) { perror("Ошибка создания файла"); return; }
    
    int n;
    printf("Введите количество записей: ");
    if (scanf("%d", &n) != 1) { fclose(f); return; } // Считываем количество записей
    
    for (int i = 0; i < n; i++) {
        Schoolchild s;
        printf("\nЗапись %d:\n", i + 1);
        printf("Фамилия: "); scanf("%49s", s.surname);
        printf("Имя: "); scanf("%49s", s.name);
        printf("Отчество: "); scanf("%49s", s.patronymic);
        printf("Класс: "); scanf("%9s", s.className);
        printf("Телефон: "); scanf("%19s", s.phone);
        printf("Оценки (математика, физика, русский, литература): ");
        scanf("%d %d %d %d", &s.grades[0], &s.grades[1], &s.grades[2], &s.grades[3]);

        /*Число 49(9, 19) означает, что scanf прочитает максимум 49(9,19) символов. 
        Поскольку массив имеет размер 50(10, 20), 50-й(10, 20) байт автоматически 
        заполнится нуль-терминатором \0. 
        Это защищает программу от переполнения буфера (классическая уязвимость), 
        если пользователь введет слишком длинную фамилию.
        */
        
        if (fwrite(&s, sizeof(Schoolchild), 1, f) != 1) {
            perror("Ошибка записи в файл");
        }
    }
    fclose(f);
    printf("Файл успешно сформирован.\n");
}

void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");  // "rb" = read binary. Только чтение.
    if (!f) { perror("Ошибка открытия файла для чтения"); return; }
    
    // Вывод красивой шапки таблицы с выравниванием (%-15s означает строку шириной 15 символов, выровненную по левому краю)
    printf("\n%-22s %-22s %-22s %-8s %-15s | %-5s %-5s %-5s %-5s\n", 
           "Фамилия", "Имя", "Отчество", "Класс", "Телефон", "Мат", "Физ", "Рус", "Лит");
    printf("--------------------------------------------------------------------------------------------\n");
    
    Schoolchild s;
    int count = 0;
    while (fread(&s, sizeof(Schoolchild), 1, f) == 1) {
        printf("%-22s %-22s %-22s %-8s %-15s | %-5s %-5s %-5s %-5s\n",
               s.surname, s.name, s.patronymic, s.className, s.phone,
               s.grades[0], s.grades[1], s.grades[2], s.grades[3]);
        count++;
    }
    if (count == 0) printf("Файл пуст.\n");
    fclose(f);
}

void deleteRecordsWithTwo(const char* filename) {
    FILE* in = fopen(filename, "rb");  // Открываем исходный для чтения
    if (!in) { perror("Ошибка открытия исходного файла"); return; }
    
    FILE* out = fopen("temp.dat", "wb"); // Открываем временный для записи
    if (!out) { perror("Ошибка создания временного файла"); fclose(in); return; }
    
    Schoolchild s;
    int deletedCount = 0, keptCount = 0;
    while (fread(&s, sizeof(Schoolchild), 1, in) == 1) { // Читаем из исходного
        if (hasGradeTwo(s)) {
            deletedCount++; // Если есть двойка, просто ничего не записываем в out (запись "исчезает")
        } else {
            fwrite(&s, sizeof(Schoolchild), 1, out); // Если двоек нет, копируем во временный файл
            keptCount++;
        }
    }
    
    fclose(in); // Закрываем оба
    fclose(out);
    remove(filename); // Удаляем старый файл с диска
    rename("temp.dat", filename); // Переименовываем временный файл в имя основного
    printf("Операция завершена. Удалено записей: %d, Осталось: %d\n", deletedCount, keptCount); 
    
}

void addToBeginning(const char* filename) {
    Schoolchild newS;
    printf("\nВведите данные нового школьника:\n");
    printf("Фамилия: "); scanf("%49s", newS.surname);
    printf("Имя: "); scanf("%49s", newS.name);
    printf("Отчество: "); scanf("%49s", newS.patronymic);
    printf("Класс: "); scanf("%9s", newS.className);
    printf("Телефон: "); scanf("%19s", newS.phone);
    printf("Оценки (мат, физ, рус, лит): ");
    scanf("%d %d %d %d", &newS.grades[0], &newS.grades[1], &newS.grades[2], &newS.grades[3]);

    FILE* in = fopen(filename, "rb");
    FILE* out = fopen("temp.dat", "wb");
    if (!out) { perror("Ошибка создания временного файла"); return; }
    
    // 1. Записываем новую запись первой
    fwrite(&newS, sizeof(Schoolchild), 1, out);
    
    // 2. Копируем старые записи следом
    if (in) {
        Schoolchild s;
        while (fread(&s, sizeof(Schoolchild), 1, in) == 1) {
            fwrite(&s, sizeof(Schoolchild), 1, out);
        }
        fclose(in);
    }
    
    fclose(out);
    remove(filename);
    rename("temp.dat", filename); // Заменяем старый файл новым, где первая запись - свежая
    printf("Запись успешно добавлена в начало файла.\n");
}

int main() {
    setlocale(LC_ALL, ".65001");
    const char* filename = "school.dat";
    int choice;

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Сформировать новый файл\n");
        printf("2. Распечатать содержимое файла\n");
        printf("3. Удалить записи с оценкой '2'\n");
        printf("4. Добавить запись в начало файла\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // очистка буфера
            continue;
        }

        switch (choice) {
            case 1: createFile(filename); break;
            case 2: printFile(filename); break;
            case 3: deleteRecordsWithTwo(filename); break;
            case 4: addToBeginning(filename); break;
            case 0: printf("Выход из программы.\n"); break;
            default: printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}