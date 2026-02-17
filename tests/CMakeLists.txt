cmake_minimum_required(VERSION 3.20)

find_package(GTest REQUIRED)

add_executable(GradeBook_tests tests_main.cpp tests_student.cpp)
target_link_libraries(GradeBook_tests PUBLIC GTest::gtest GradeCourse_lib)

add_test(AllTestsMain GradeBook_tests)
