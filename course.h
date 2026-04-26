#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
private:
    string courseCode;
    string courseName;

public:
    Course(string code, string name) : courseCode(code), courseName(name) {}
    string getCode() const { return courseCode; }
    string getName() const { return courseName; }
};

#endif