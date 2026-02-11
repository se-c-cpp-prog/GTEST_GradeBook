#pragma once

#include <string>
#include <vector>

class Student
{
  private:
	std::string name_;
	int id_;
	std::vector< int > grades_;

  public:
	Student(const std::string &name, int id);

	std::string getName() const;
	int getId() const;
	std::vector< int > getGrades() const;

	void addGrade(int grade);
	double getAverage() const;
	bool hasPassingGrade() const;
};
