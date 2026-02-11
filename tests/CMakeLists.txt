cmake_minimum_required(VERSION 3.20)

find_package(GTest CONFIG REQUIRED)

add_executable(GradeBook_tests main.cpp
                                test_Student.cpp
)

target_link_libraries(GradeBook_tests
    PRIVATE
    GradeBook_lib
    GTest::gtest
)

add_test(NAME all_test COMMAND GradeBook_tests)
