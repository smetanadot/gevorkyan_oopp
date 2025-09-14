#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "student.h""

class group {
private:

	std::string group_name;

	std::vector<student*> group_students;

public:

	void add_student();

	const void show_all_students();

	void read_students_from_file(std::ifstream& in_file);

	void write_students_to_file(std::ofstream& out_file);

	void delete_all_students();

	void set_group_name(const std::string& name);

	const std::string get_group_name();

};