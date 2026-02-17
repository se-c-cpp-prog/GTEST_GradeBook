#include "student.h"

Student::Student(const std::string &name, int id) : name_(name), id_(id) {}

std::string Student::getName() const
{
	return name_;
}

int Student::getId() const
{
	return id_;
}

std::vector< int > Student::getGrades() const
{
	return grades_;
}

void Student::addGrade(int grade)
{
	grades_.push_back(grade);
}

double Student::getAverage() const
{
	if (grades_.empty())
	{
		return 0.0;
	}

	double sum = 0;
	for (size_t i = 0; i < grades_.size(); i++)
	{
		sum += grades_[i];
	}

	return sum / grades_.size();
}

bool Student::hasPassingGrade() const
{
	return !grades_.empty() && getAverage() >= 60.0;
}
