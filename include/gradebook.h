#pragma once

#include <string>
#include <vector>
#include <map>

class Student;
class Course;

class GradeBook {
private:
    std::string semester_;
    std::map<int, std::vector<int>> studentGrades_;
    std::vector<Student*> allStudents_;
    std::vector<Course*> allCourses_;

public:
    explicit GradeBook(const std::string& semester);

    std::string getSemester() const;

    void addStudent(Student* student);
    void addCourse(Course* course);
    void recordGrade(int studentId, int grade);

    Student* findStudent(int studentId) const;
    Course* findCourse(const std::string& code) const;

    double getStudentAverage(int studentId) const;
    double getCourseAverage(const std::string& courseCode) const;
    bool isStudentPassing(int studentId) const;
};
