#include "course.h"
#include "student.h"
#include <algorithm>

Course::Course(const std::string& name, const std::string& code)
    : name_(name), code_(code) {}

std::string Course::getName() const {
    return name_;
}

std::string Course::getCode() const {
    return code_;
}

std::vector<Student*> Course::getStudents() const {
    return students_;
}

void Course::enrollStudent(Student* student) {
    if (student && !hasStudent(student->getId())) {
        students_.push_back(student);
    }
}

void Course::removeStudent(int studentId) {
    students_.erase(
        std::remove_if(students_.begin(), students_.end(),
            [studentId](Student* s) {
                return s->getId() == studentId;
            }),
        students_.end()
    );
}

int Course::getStudentCount() const {
    return static_cast<int>(students_.size());
}

bool Course::hasStudent(int studentId) const {
    return std::any_of(students_.begin(), students_.end(),
        [studentId](Student* s) {
            return s->getId() == studentId;
        });
}
