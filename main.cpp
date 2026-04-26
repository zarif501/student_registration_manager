#include <iostream>
#include "course.h"
#include "student.h"
#include "registrationmanager.h"

using namespace std;

int main()
{
    registrationmanager manager;

    // Create Courses
    Course *c1 = new Course("CENG201", "Data Structures");
    Course *c2 = new Course("MATH102", "Calculus II");

    cout << "=== Student Registration System ===\n"
         << endl;

    // Test Cases
    manager.addStudent(103, "Atlas Cadirci");
    manager.addStudent(101, "Neva Ekin Akcay");
    manager.addStudent(102, "Halil Mert Bal");

    cout << "Sorting students by ID..." << endl;
    manager.sortStudents();

    manager.enrollStudentInCourse(101, c1);
    manager.enrollStudentInCourse(101, c2);

    cout << "\n--- Current List ---" << endl;
    manager.displayAllStudents();

    cout << "\nDropping CENG201 for ID 101..." << endl;
    Student *s = manager.searchStudent(101);
    if (s)
        s->dropCourse("CENG201");

    manager.displayAllStudents();

    return 0;
}