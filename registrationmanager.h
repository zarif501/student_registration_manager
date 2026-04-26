#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class registrationmanager
{
private:
    StudentNode *head;

public:
    registrationmanager() : head(nullptr) {}

    void addStudent(int id, string name)
    {
        Student *s = new Student(id, name);
        StudentNode *newNode = new StudentNode(s);
        newNode->next = head;
        head = newNode;
    }

    Student *searchStudent(int id)
    {
        StudentNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->student->getID() == id)
                return temp->student;
            temp = temp->next;
        }
        return nullptr;
    }

    void enrollStudentInCourse(int id, Course *c)
    {
        Student *s = searchStudent(id);
        if (s)
            s->addCourse(c);
        else
            cout << "Error: ID " << id << " not found." << endl;
    }

    void removeStudent(int id)
    {
        StudentNode *curr = head, *prev = nullptr;
        while (curr != nullptr && curr->student->getID() != id)
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
            delete curr->student;
            delete curr;
        }
    }

    // Sort students by ID - Required by PDF
    void sortStudents()
    {
        if (!head || !head->next)
            return;
        bool swapped;
        do
        {
            swapped = false;
            StudentNode *curr = head;
            while (curr->next != nullptr)
            {
                if (curr->student->getID() > curr->next->student->getID())
                {
                    Student *temp = curr->student;
                    curr->student = curr->next->student;
                    curr->next->student = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    void displayAllStudents()
    {
        StudentNode *temp = head;
        if (!temp)
        {
            cout << "System is empty." << endl;
            return;
        }
        while (temp != nullptr)
        {
            temp->student->display();
            temp = temp->next;
        }
    }
};

#endif