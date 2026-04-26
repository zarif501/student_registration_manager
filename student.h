#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "course.h" // Important: Student needs to see Course

using namespace std;

// Node for the student's personal course list
struct CourseNode
{
    Course *course;
    CourseNode *next;
    CourseNode(Course *c) : course(c), next(nullptr) {}
};

class Student
{
private:
    int studentID;
    string name;
    CourseNode *head;

public:
    Student(int id, string n) : studentID(id), name(n), head(nullptr) {}

    int getID() const { return studentID; }
    string getName() const { return name; }

    // Adds a course - Complexity: O(1)
    void addCourse(Course *c)
    {
        CourseNode *newNode = new CourseNode(c);
        newNode->next = head;
        head = newNode;
    }

    // Drop a course - Required by PDF
    void dropCourse(string code)
    {
        CourseNode *curr = head, *prev = nullptr;
        while (curr != nullptr && curr->course->getCode() != code)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
            delete curr;
        }
    }

    void display() const
    {
        cout << "ID: " << studentID << " | Name: " << name << endl;
        cout << "Courses: ";
        CourseNode *temp = head;
        if (!temp)
            cout << "No courses.";
        while (temp != nullptr)
        {
            cout << "[" << temp->course->getCode() << "] ";
            temp = temp->next;
        }
        cout << "\n---------------------------" << endl;
    }
};

// Node to link students in the Manager
struct StudentNode
{
    Student *student;
    StudentNode *next;
    StudentNode(Student *s) : student(s), next(nullptr) {}
};

#endif