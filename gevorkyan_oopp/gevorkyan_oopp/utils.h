#pragma once
#include <iostream>
#include "student.h"

class utils
{
private:

	std::unordered_map<int, student> students;

public:

	static void save_objects(const std::unordered_map<int, student>& students);

};
int verification(int minvalue, int maxvalue);


