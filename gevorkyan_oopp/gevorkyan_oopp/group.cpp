#include "group.h"
#include "student.h"
#include <iostream>

using namespace std;

group::~group() {
    delete_all_students();
}

void group::set_group_name(const wstring& name) {
    group_name = name;
    for (student* student : group_students) {
        student->set_student_group(group_name);
    }
}

void group::add_student() {
    student* new_student = new student();
    new_student->add_student();
    new_student->set_student_group(group_name);
    group_students.push_back(new_student);
}

const void group::show_all_students() {
    wcout << L"Группа: " << group_name << endl;

    if (group_students.size() == 0) {
        wcout << L"Группа пуста" << endl;
    }

    for (student* student : group_students) {
        student->show_student();
        wcout << L"------------------------------" << endl;
    }
}

void group::delete_all_students() {
    for (student* student : group_students) {
        delete student;
    }
    group_students.clear();
    set_group_name(L"Default");
    wcout << L"Группа очищена" << endl;
}

void group::load_students_from_file(wifstream& in_file) {
    getline(in_file, group_name);
    int max_id = 0;
    int student_count;
    in_file >> student_count;
    in_file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < student_count; ++i) {
        student* new_student = new student();
        new_student->load_student(in_file);
        new_student->set_student_group(group_name);

        if (!in_file.fail()) {
            group_students.push_back(new_student);
            if (new_student->get_student_id() > max_id) {
                max_id = new_student->get_student_id();
            }
        }
        else {
            delete new_student;
            wcout << L"Ошибка в загрузке файла" << endl;
            break;
        }
    }

    student s;
    s.set_student_max_id(max_id + 1);
    in_file.close();
    wcout << L"Загружено" << endl;
}

void group::save_students_to_file(wofstream& out_file) {
    out_file << group_name << endl;
    out_file << group_students.size() << endl;

    for (student* student : group_students) {
        student->save_student(out_file);
    }

    out_file.close();
    wcout << L"Сохранено" << endl;
}

const wstring group::get_group_name() {
    return group_name;
}