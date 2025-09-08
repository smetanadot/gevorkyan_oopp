#pragma once

#include <iostream>
#include <vector>
#include <string>



class group {
private:
	
	std::string group_name;

public:

	group(const std::string& name);

	void set_group_name(const std::string& name);

	std::string get_group_name() const;

};


