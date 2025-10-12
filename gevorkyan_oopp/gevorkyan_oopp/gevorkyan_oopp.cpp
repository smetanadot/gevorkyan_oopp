#include <iostream>
#include <sstream>
#include <limits>
#include <locale>
#include <codecvt>
#include "student.h"
#include "group.h"
#include <C:\local\boost_1_89_0\boost\serialization\access.hpp>

using namespace std;

BOOST_CLASS_EXPORT_IMPLEMENT(student)
BOOST_CLASS_EXPORT_IMPLEMENT(headman)

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
    wcout << L"2. Добавить старосту" << endl;
    wcout << L"3. Показать всех студентов" << endl;
    wcout << L"4. Сохранить группу в файл" << endl;
    wcout << L"5. Загрузить группу из файла" << endl;
    wcout << L"6. Удалить всех студентов" << endl;
    wcout << L"7. Изменить название группы" << endl;
    wcout << L"0. Выход" << endl;
}

int main() {

    setlocale(LC_ALL, "rus");
    locale::global(locale("rus_rus.866"));
    wcin.imbue(locale("rus_rus.866"));
    wcout.imbue(locale("rus_rus.866"));

    group _group(L"DEFAULT");
    wstring filename;
    int action;

    while (true) {
        menu();
        action = int_verification(0, 7);

        switch (action) {
        case 1: {
            _group.add_student(make_shared<student>());
            break;
        }
        case 2:
        {
            _group.add_student(make_shared<headman>());
            break;
        }
        case 3: {
            _group.show_all_students();
            break;
        }
        case 4: {
            wcout << L"Введите имя файла: ";
            
            getline(wcin, filename);
            filename += L".txt";
            ofstream in_file(filename, ios::binary);
            _group.save_students_to_file(in_file);
            break;
        }
        case 5: {
            wcout << L"Введите имя файла: ";
            getline(wcin, filename);
            filename += L".txt";
            ifstream out_file(filename, ios::binary);
            out_file.open(filename);
            if (!out_file.is_open()) {
                wcout << L"Не могу открыть файл: " << filename << endl;
                out_file.close();
                break;
            }
            _group.load_students_from_file(out_file);
            break;
        }
        case 6: {
            _group.delete_all_students();
            wcout << L"Успешно" << endl;
            break;
        }
        case 7: {
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