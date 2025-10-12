#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>

class student {
protected:
    int student_id;
    std::wstring student_name;
    std::wstring student_surname;
    int student_age;
    std::wstring student_group;
public:
    student() : student_id(0), student_name(L""), student_surname(L""), student_age(0), student_group(L"") {};
    student(int student_id, std::wstring& student_name, std::wstring& student_surname, int student_age, std::wstring& student_group);
    virtual ~student();
    virtual void show_student();
    virtual void add_student();
    void set_student_group(std::wstring& student_group_name);
    void set_student_id(int& id);
    int get_student_id();
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& student_id;
        ar& student_name;
        ar& student_surname;
        ar& student_age;
        ar& student_group;
    }
};

BOOST_CLASS_EXPORT_KEY(student)