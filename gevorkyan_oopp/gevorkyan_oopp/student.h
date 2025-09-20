#pragma once
#include <string>
#include <iostream>
#include <fstream>

class student {
private:
    static int student_max_id;
    int student_id;
    std::wstring student_name;
    std::wstring student_surname;
    int student_age;
    std::wstring student_group;
public:
    const void show_student();
    void add_student();
    void save_student(std::wofstream& out_file);
    void load_student(std::wifstream& in_file);
    void set_student_group(std::wstring& student_group_name);
    void set_student_max_id(const int& new_student_max_id);
    const int get_student_id();
};