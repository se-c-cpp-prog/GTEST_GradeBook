#include <gtest/gtest.h>

#include <student.h>

// Студент успешно получает среднюю оценку
// Студент получает оценку
// Студент аттестован ли?

// AAA -> Arrange Act Assert

// [ТестируемыйМетод]_[Сценарий]_[Резульатт]
//

// Фабричные методы
// new Student("CPP", 1);
// addGrade()

TEST(Students_test, addGrade){
    // Arrange -> Given
    // SUT - System Under Test (Система которую тестируют)
    Student* sut = new Student("CPP", 1);
    int grade = 4;

    // Act -> When
    // MUT - Method Under Test (Метод который теструют)
    sut->addGrade(grade);

    // Assert -> Then
    std::vector<int> result = sut->getGrades();

    int expectedLenght = 1;
    int expectedGrade = 4;

    EXPECT_EQ(result.size(), expectedLenght);
    EXPECT_EQ(result[0], expectedGrade);
}
