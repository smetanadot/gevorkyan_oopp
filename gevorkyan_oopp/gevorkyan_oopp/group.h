#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "student.h"

class group {
private:
    std::wstring group_name;
    std::vector<student*> group_students;

public:
    ~group();
    void add_student();
    const void show_all_students();
    void load_students_from_file(std::wifstream& in_file);
    void save_students_to_file(std::wofstream& out_file);
    void delete_all_students();
    void set_group_name(const std::wstring& name);
    const std::wstring get_group_name();
};