#pragma once
#include <string>
#include <iostream>
#include <fstream>



class student {
private:

	static int student_max_id;

	int student_id;

	std::string student_name;

	std::string student_surname;

	int student_age;

	std::string student_group;

public:

	const void show_student();

	void add_student();

	void save_student(std::ofstream& out_file);

	void load_student(std::ifstream& in_file);

	void set_student_group(std::string& student_group_name);

	void set_student_max_id(const int& new_student_max_id);

	const int get_student_id();

	

};