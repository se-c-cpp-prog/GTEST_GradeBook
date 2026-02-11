#pragma once

#include <string>
#include <vector>

class Student;

class Course {
private:
    std::string name_;
    std::string code_;
    std::vector<Student*> students_;

public:
    Course(const std::string& name, const std::string& code);

    std::string getName() const;
    std::string getCode() const;
    std::vector<Student*> getStudents() const;

    void enrollStudent(Student* student);
    void removeStudent(int studentId);
    int getStudentCount() const;
    bool hasStudent(int studentId) const;
};
