#include "student.h"

#include <algorithm>
#include <numeric>

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
	return static_cast< double >(std::accumulate(grades_.begin(), grades_.end(), 0)) / grades_.size();
}

bool Student::hasPassingGrade() const
{
	return !grades_.empty() && getAverage() >= 60.0;
}
