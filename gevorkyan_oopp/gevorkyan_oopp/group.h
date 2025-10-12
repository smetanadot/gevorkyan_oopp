#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "student.h"
#include "headman.h"
#include <C:\local\boost_1_89_0\boost\archive/binary_oarchive.hpp>
#include <C:\local\boost_1_89_0\boost\archive/binary_iarchive.hpp>
#include <C:\local\boost_1_89_0\boost/serialization/shared_ptr.hpp>
#include <C:\local\boost_1_89_0\boost\serialization/string.hpp>
#include <C:\local\boost_1_89_0\boost\serialization/vector.hpp>

class group {
private:
    std::wstring group_name;
    std::vector<std::shared_ptr<student>> group_students;
    int id;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& group_name;
        ar& id;
        ar& group_students;
    }
public:
    ~group();
    group(const std::wstring& group_name = L"");
    void add_student(std::shared_ptr<student> s);
    void show_all_students();
    void load_students_from_file(std::ifstream& in_file);
    void save_students_to_file(std::ofstream& out_file);
    void delete_all_students();
    void set_group_name(const std::wstring& name);
    std::wstring get_group_name();
};