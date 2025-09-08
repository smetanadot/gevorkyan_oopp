#include <iostream>
#include <unordered_map>
#include <fstream>
#include "student.h"
#include "utils.h"

using namespace std;



int verification(int minvalue, int maxvalue) // verification of int data
{
	int value;
	while (true)
	{
		if ((cin >> value).good() && value >= minvalue && value <= maxvalue)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			return value;
		}
		else
		{
			cout << "Incorrect data. Please, try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

void utils::save_objects(const std::unordered_map<int, student>& students)
{
	string txt;
	cout << "Enter file name: " << endl;
	getline(cin, txt);
	ofstream fout;
	fout.open(txt + ".txt");

	if (!fout.is_open())
	{
		cout << "Cannot open file" << endl;
		return;
	}

	for (auto& pair : students)
	{
		pair.second.save_student(fout);
	}
}