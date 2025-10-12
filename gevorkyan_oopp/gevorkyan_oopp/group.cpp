#include "group.h"
#include <iostream>

using namespace std;

group::~group() {
    delete_all_students();
}

group::group(const wstring& name) : group_name(name), id(1) {}


void group::set_group_name(const wstring& name) {
    group_name = name;
    for (auto& student : group_students) {
        student->set_student_group(group_name);
    }
}

void group::add_student(shared_ptr<student> s) {
    auto new_student = s;
    new_student->add_student();
    new_student->set_student_id(id);
    id++;
    new_student->set_student_group(group_name);
    group_students.push_back(new_student);
}

void group::show_all_students() {
    wcout << L"Группа: " << group_name << endl;

    if (group_students.size() == 0) {
        wcout << L"Группа пуста" << endl;
    }

    for (auto& student : group_students) {
        student->show_student();
        wcout << L"------------------------------" << endl;
    }
}

void group::delete_all_students() {
    group_students.clear();
    id = 1;
    wcout << L"Группа очищена" << endl;
}

void group::load_students_from_file(ifstream& in_file) {
    boost::archive::binary_iarchive ia(in_file);
    ia >> *this;
    wcout << L"Загружено" << endl;
}

void group::save_students_to_file(ofstream& out_file) {
    boost::archive::binary_oarchive oa(out_file);
    oa << *this;
    wcout << L"Сохранено" << endl;
}

wstring group::get_group_name() {
    return group_name;
}

