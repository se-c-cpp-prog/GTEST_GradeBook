#pragma once

#include <string>
#include <vector>

// 1, Unit - часть кода -> класс, изоляция unitов
// 2. Unit - единица поведения -> тест атомарный факт, изоляция тестов

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

	// Получение средней оценки
	double getAverage() const;
	// Добавление оценки
	void addGrade(int grade);
	// Закрылся ли студент (60>=)
	bool hasPassingGrade() const;
};
