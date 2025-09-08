#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class student {
private:

	static int MaxID;
	
	int id;

	std::string student_name;

	std::string student_surname;

	int age;


public:

	int get_id();
	
	void add_student();

	void show_student(const std::unordered_map<int, student>& students);

	void save_student(std::ofstream& fout) const;
};