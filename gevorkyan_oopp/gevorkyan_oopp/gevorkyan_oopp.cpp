#include <iostream>
#include <unordered_map>
#include "student.h"
#include "group.h"
#include "utils.h"

using namespace std;




void menu()
{
    cout <<
        "1. Set group name\n" <<
        "2. Show current group name\n" << 
        "3. Add student\n" <<
        "4. Show students\n" <<
        "5. Save list of students\n" <<
        "6. Load list of students\n" <<
        "0. Exit" << endl;
}

int main()
{
    group _group("default");
    student _student;
    utils _utils;
    
    unordered_map <int, student> students;


    while (true)
    {
        menu();
        int action;
        cin >> action;
        cin.ignore();

        switch (action)
        {
            case(1):
            {
                cout << "Enter group name: "<< endl;
                string name;
                getline(cin, name);
                _group.set_group_name(name);
                break;
            }
            case(2):
            {
                cout << "Group name: " << endl;
                cout << _group.get_group_name() << endl;
                break;
            }
            case(3):
            {
                _student.add_student();
                students.emplace(_student.get_id(), _student);
                break;
            }
            case(4):
            {
                _student.show_student(students);
                break;
            }
            case(5):
            {
                _utils.save_objects(students);
                break;
            }
            case(6):
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
