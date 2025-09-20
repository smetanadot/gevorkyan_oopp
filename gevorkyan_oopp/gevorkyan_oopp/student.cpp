#include "student.h"
#include <iostream>

using namespace std;

int student::student_max_id = 1;

const void student::show_student() {
    wcout << L"ID: " << student_id << endl
        << L"Имя: " << student_name << endl
        << L"Фамилия: " << student_surname << endl
        << L"Возраст: " << student_age << endl
        << L"Группа: " << student_group << endl;
}

void student::add_student() {
    wcout << L"Введите имя: " << endl; 
    getline(wcin, student_name);
    wcout << L"Введите фамилию: " << endl;
    getline(wcin, student_surname);
    wcout << L"Введите возраст: " << endl;
    wcin >> student_age;

    student_id = student_max_id;
    student_max_id++;
}

void student::save_student(wofstream& out_file) {
    out_file << student_id << endl
        << student_name << endl
        << student_surname << endl
        << student_age << endl
        << student_group << endl;
}

void student::load_student(wifstream& in_file) {
    in_file >> student_id;
    in_file.ignore(256, '\n');

    getline(in_file, student_name);
    getline(in_file, student_surname);

    in_file >> student_age;
    in_file.ignore(256, '\n');

    getline(in_file, student_group);
}

void student::set_student_group(wstring& student_group_name) {
    student_group = student_group_name;
}

const int student::get_student_id() {
    return student_id;
}

void student::set_student_max_id(const int& new_student_max_id) {
    student_max_id = new_student_max_id;
}