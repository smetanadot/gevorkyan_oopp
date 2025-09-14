#include <iostream>
#include <sstream>
#include <limits>
#include "student.h"
#include "group.h"

using namespace std;

int int_verification(int min_value, int max_value) {
	int value;
	while (true) {
		if ((cin >> value).good() && value >= min_value && value <= max_value) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
		else {
			cout << "Incorrect data. Try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void menu() {
	cout << "1. Add student" << endl;
	cout << "2. Show all students" << endl;
	cout << "3. Save group to file" << endl;
	cout << "4. Load group from file" << endl;
	cout << "5. Delete all students" << endl;
	cout << "6. Change group name" << endl;
	cout << "0. Exit" << endl;
}

int main() {

	group _group;
	_group.set_group_name("Default");

	string filename;
	int action;

	while (true)
	{

		menu();
		action = int_verification(0, 6);

		switch (action) 
		{
			case 1:
			{

				_group.add_student();
				break;

			}
			case 2:
			{

				_group.show_all_students();
				break;

			}
			case 3: 
			{

				cout << "Enter file name: ";

				getline(cin, filename);
				filename += ".txt";
				ofstream in_file;
				in_file.open(filename);
				_group.write_students_to_file(in_file);
				break;

			}
			case 4: 
			{

				cout << "Enter file name: ";

				getline(cin, filename);
				filename += ".txt";

				ifstream out_file;
				out_file.open(filename);
				
				if (!out_file.is_open())
				{
					cout << "Can't open file with name: " << filename << endl;
					out_file.close();
					break;
				}
				_group.read_students_from_file(out_file);
				break;

			}
			case 5:
			{

				_group.delete_all_students();
				cout << "Successfully" << endl;
				break;

			}
			case 6:
			{
				
				string new_group_name;

				cout << "Current new group name: " << _group.get_group_name() << endl;
				cout << "Enter new group name: ";

				getline(cin, new_group_name);
				_group.set_group_name(new_group_name);

				cout << "Successfully" << endl;

				break;

			}
			case 0:
			{
				return 0;
			}
		}
	}
}