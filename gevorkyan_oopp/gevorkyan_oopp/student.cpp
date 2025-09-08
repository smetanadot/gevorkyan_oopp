#include <iostream>
#include <unordered_map>
#include <fstream>
#include "student.h"
#include "utils.h"

using namespace std;



int student::MaxID = 1;

int student::get_id()
{
	return id;
}

void student::add_student()
{

	cout << endl;

	cout << "Enter name: " << endl;
	getline(cin, student_name);

	cout << "Enter surname: " << endl;
	getline(cin, student_surname);

	cout << "Enter age: " << endl;
	age = verification(0, 100);

	cout << endl;

	id = MaxID;
	MaxID++;

}

void student::show_student(const unordered_map<int, student>& students)
{
	if (students.empty())
	{
		cout << "List is empty" << endl;
		return;
	}

	for (const auto& pair : students)
	{
		const student& s = pair.second;
		cout << "id: " << s.id << endl
			<< s.student_name << " " << s.student_surname << endl
			<< "age: " << s.age << endl;

	}
}

void student::save_student(ofstream& fout) const
{
	fout << id << endl;
	fout << student_name << endl;
	fout << student_surname << endl;
	fout << age << endl;
}