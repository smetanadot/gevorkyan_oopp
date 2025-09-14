#include "student.h"

using namespace std;

int student::student_max_id = 1;

const void student::show_student() 
{

	cout << "ID: " << student_id << endl
		<< "Name: " << student_name << endl
		<< "Surname: " << student_surname << endl
		<< "Age: " << student_age << endl
		<< "Group: " << student_group << endl;

}

void student::add_student() 
{
	cout << "Enter name: ";
	cin >> student_name;
	cout << "Enter surname: ";
	cin >> student_surname;
	cout << "Enter age: ";
	cin >> student_age;

	student_id = student_max_id;
	student_max_id++;

}

void student::save_student(ofstream& out_file) 
{
	out_file << student_id << endl
		<< student_name << endl
		<< student_surname << endl
		<< student_age << endl
		<< student_group << endl;
}

void student::load_student(ifstream& in_file) 
{

	in_file >> student_id;
	in_file.ignore(10000,'\n');

	getline(in_file, student_name);

	getline(in_file, student_surname);

	in_file >> student_age;

	getline(in_file, student_group);
	in_file.ignore(10000, '\n');

}

void student::set_student_group(string& student_group_name) 
{
	student_group = student_group_name;
}

const int student::get_student_id() 
{
	return student_id;
}

void student::set_student_max_id(const int& new_student_max_id)
{
	student_max_id = new_student_max_id;
}