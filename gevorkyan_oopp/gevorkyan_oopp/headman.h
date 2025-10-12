#pragma once
#include "student.h"

class headman : public student {
private: 
	std::wstring phone_number;
public:
	headman();
	headman(int student_id, std::wstring& student_name, std::wstring& student_surname, int student_age, std::wstring& student_group, std::wstring& phone_number);
	void show_student() override;
	void add_student() override;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<student>(*this);
		ar& phone_number;
	}
};

BOOST_CLASS_EXPORT_KEY(headman)