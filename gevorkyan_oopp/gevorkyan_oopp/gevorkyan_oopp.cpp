#include <iostream>
#include <sstream>
#include <limits>
#include <locale>
#include <codecvt>
#include "student.h"
#include "group.h"

using namespace std;


int int_verification(int min_value, int max_value) {
    int value;
    while (true) {
        if ((wcin >> value).good() && value >= min_value && value <= max_value) {
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else {
            wcout << L"Incorrect data. Try again" << endl;
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void menu() {
    wcout << L"1. Добавить студента" << endl;
    wcout << L"2. Показать всех студентов" << endl;
    wcout << L"3. Сохранить группу в файл" << endl;
    wcout << L"4. Загрузить группу из файла" << endl;
    wcout << L"5. Удалить всех студентов" << endl;
    wcout << L"6. Изменить название группы" << endl;
    wcout << L"0. Выход" << endl;
}

int main() {

    setlocale(LC_ALL, "rus");
    locale::global(locale("rus_rus.866"));
    wcin.imbue(locale("rus_rus.866"));
    wcout.imbue(locale("rus_rus.866"));

    group _group;
    _group.set_group_name(L"Default");

    wstring filename;
    int action;

    while (true) {
        menu();
        action = int_verification(0, 6);

        switch (action) {
        case 1: {
            _group.add_student();
            break;
        }
        case 2: {
            _group.show_all_students();
            break;
        }
        case 3: {
            wcout << L"Введите имя файла: ";
            getline(wcin, filename);
            filename += L".txt";
            wofstream in_file;
            
            in_file.open(filename);
            in_file.imbue(locale("rus_rus.866"));
            _group.save_students_to_file(in_file);
            break;
        }
        case 4: {
            wcout << L"Введите имя файла: ";
            getline(wcin, filename);
            filename += L".txt";

            wifstream out_file;
            out_file.open(filename);
            out_file.imbue(locale("rus_rus.866"));

            if (!out_file.is_open()) {
                wcout << L"Не могу открыть файл: " << filename << endl;
                out_file.close();
                break;
            }
            _group.load_students_from_file(out_file);
            break;
        }
        case 5: {
            _group.delete_all_students();
            wcout << L"Успешно" << endl;
            break;
        }
        case 6: {
            wstring new_group_name;
            wcout << L"Текущее название группы: " << _group.get_group_name() << endl;
            wcout << L"Введите новое название группы: ";
            getline(wcin, new_group_name);
            _group.set_group_name(new_group_name);
            wcout << L"Успешно" << endl;
            break;
        }
        case 0: {
            return 0;
        }
        }
    }
}