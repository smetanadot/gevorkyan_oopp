#include <iostream>
#include <string>
#include "group.h"



group::group(const std::string& name) : group_name(name) {}

void group::set_group_name(const std::string& name) {

	group_name = name;

}

std::string group::get_group_name() const {
	
	return group_name;

}