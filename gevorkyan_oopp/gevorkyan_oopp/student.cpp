#include "student.h"

using namespace std;

student::student(int student_id, std::wstring& student_name, std::wstring& student_surname, int student_age, std::wstring& student_group) : student_id(student_id), student_name(student_name), student_surname(student_surname), student_age(student_age), student_group(student_group) {};

student::~student() {}


void student::show_student() {
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
}


void student::set_student_group(wstring& student_group_name) {
    student_group = student_group_name;
}

void student::set_student_id(int& id) {
    student_id = id;
}

int student::get_student_id() {
    return student_id;
}
