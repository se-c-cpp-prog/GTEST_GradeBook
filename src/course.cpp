#include "course.h"

#include "student.h"

Course::Course(const std::string &name, const std::string &code) : name_(name), code_(code) {}

std::string Course::getName() const
{
	return name_;
}

std::string Course::getCode() const
{
	return code_;
}

std::vector< Student * > Course::getStudents() const
{
	return students_;
}

void Course::enrollStudent(Student *student)
{
	if (student && !hasStudent(student->getId()))
	{
		students_.push_back(student);
	}
}

void Course::removeStudent(int studentId)
{
	for (size_t i = 0; i < students_.size(); i++)
	{
		if (students_[i]->getId() == studentId)
		{
			students_.erase(students_.begin() + i);
			return;
		}
	}
}

size_t Course::getStudentCount() const
{
	return students_.size();
}

bool Course::hasStudent(int studentId) const
{
	for (size_t i = 0; i < students_.size(); i++)
	{
		if (students_[i]->getId() == studentId)
		{
			return true;
		}
	}

	return false;
}
