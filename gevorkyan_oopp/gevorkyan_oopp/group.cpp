#include "group.h"
#include "student.h"

using namespace std;

void group::set_group_name(const std::string& name) 
{
	group_name = name;
	for (student* student : group_students) {
		student->set_student_group(group_name);
	}
}

void group::add_student() 
{

	student* new_student = new student();
	new_student->add_student();
	new_student->set_student_group(group_name);
	group_students.push_back(new_student);

}

const void group::show_all_students() 
{

	cout << "Group: " << group_name << endl;

	if (group_students.size() == 0) 
	{
		cout << "Group is empty" << endl;
	}

	for (student* student : group_students) 
	{
		student->show_student();
		cout << "------------------------------" << endl;
	}
}

void group::delete_all_students() 
{
	for (student* student : group_students) 
	{
		delete student;
	}
	group_students.clear();

	cout << "Group was cleared" << endl;
}

void group::read_students_from_file(ifstream& in_file) 
{
	getline(in_file, group_name);
	int max_id = 0;
	int student_count;
	in_file >> student_count;
	cout << student_count << endl;
	in_file.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < student_count; ++i) 
	{
		
		student* new_student = new student();
		new_student->load_student(in_file);
		new_student->set_student_group(group_name);

		new_student->show_student();

		if (!in_file.fail()) 
		{
			group_students.push_back(new_student);
			if (new_student->get_student_id() > max_id) 
			{
				max_id = new_student->get_student_id();
			}
		}
		else 
		{
			delete new_student;
			cout << "Error reading student data from file" << endl;
			break;
		}
	}
	
	student s;
	s.set_student_max_id(max_id + 1);

	in_file.close();
	cout << "Loaded" << endl;
}

void group::write_students_to_file(ofstream& out_file) 
{
	
	out_file << group_name << endl;
	out_file << group_students.size() << endl;
	
	for (student* student : group_students) 
	{
		student->save_student(out_file);
	}
	
	out_file.close();
	cout << "Saved" << endl;

}

const string group::get_group_name() 
{
	return group_name;
}
