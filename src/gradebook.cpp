#include "gradebook.h"
#include "course.h"
#include "student.h"

GradeBook::GradeBook(const std::string &semester) : semester_(semester) {}

std::string GradeBook::getSemester() const { return semester_; }

void GradeBook::addStudent(Student *student) {
  if (student && !findStudent(student->getId())) {
    allStudents_.push_back(student);
  }
}

void GradeBook::addCourse(Course *course) {
  if (course && !findCourse(course->getCode())) {
    allCourses_.push_back(course);
  }
}

void GradeBook::recordGrade(int studentId, int grade) {
  studentGrades_[studentId].push_back(grade);
}

Student *GradeBook::findStudent(int studentId) const {
  for (const auto &student : allStudents_) {
    if (student->getId() == studentId) {
      return student;
    }
  }
  return nullptr;
}

Course *GradeBook::findCourse(const std::string &code) const {
  for (const auto &course : allCourses_) {
    if (course->getCode() == code) {
      return course;
    }
  }
  return nullptr;
}

double GradeBook::getStudentAverage(int studentId) const {
  auto it = studentGrades_.find(studentId);
  if (it == studentGrades_.end() || it->second.empty()) {
    return 0.0;
  }
  double sum = 0;
  for (int grade : it->second) {
    sum += grade;
  }
  return sum / it->second.size();
}

double GradeBook::getCourseAverage(const std::string &courseCode) const {
  auto course = findCourse(courseCode);
  if (!course) {
    return 0.0;
  }

  double sum = 0;
  int count = 0;
  for (const auto &student : course->getStudents()) {
    double avg = getStudentAverage(student->getId());
    if (avg > 0) {
      sum += avg;
      count++;
    }
  }
  return count > 0 ? sum / count : 0.0;
}

bool GradeBook::isStudentPassing(int studentId) const {
  return getStudentAverage(studentId) >= 60.0;
}
