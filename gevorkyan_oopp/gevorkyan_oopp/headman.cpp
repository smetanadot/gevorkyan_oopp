#include "headman.h"

using namespace std;

headman::headman() : student() {}

headman::headman(int student_id, std::wstring& student_name, std::wstring& student_surname, int student_age, std::wstring& student_group, std::wstring& phone_number) : student(student_id, student_name, student_surname, student_age, student_group), phone_number(phone_number) {}

void headman::show_student() {
	wcout << L"СТАРОСТА" << endl;
	student::show_student();
	wcout << L"Номер телефона: " << phone_number << endl;
}

void headman::add_student() {
	student::add_student();
	wcout << L"Введите номер телефона: " << endl;
	wcin.ignore(256, '\n');
	getline(wcin, phone_number);
}