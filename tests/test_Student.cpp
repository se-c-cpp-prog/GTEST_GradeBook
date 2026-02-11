#include "../include/student.h"

#include <gtest/gtest.h>

#include <vector>

// Студент получил оценку и она правильно сохранилась
//
// Студенту поставили оценки, нужно проверить что средний считается правильно
//
// Студент получил зачет

// [Тестируемый метод]_[Сценарий]_[Ожидаемый результат]
// RotateProductToCudaNubid_RotateTo_Complete
// Student_Get_Grade_Four_And_Get_Five
TEST(Student_Grade, Student_Get_Grade)
{
	// Arrange -> Given
	// SUT - System Under Test
	// MUT - Method Under Test
	Student sut = Student("Alex", 1);
	int expectGrade = 10;

	// Act -> When
	sut.addGrade(expectGrade);

	// Assert -> Then
	std::vector< int > result = sut.getGrades();

	int expectlenght = 1;
	// EXPECT_EQ(фактическое, ожидаемое)
	EXPECT_EQ(result.size(), expectlenght);
	EXPECT_EQ(result[0], expectGrade);
}
