cmake_minimum_required(VERSION 3.20)

project(GradeCourse VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # -> json

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_executable()
add_library(GradeCourse_lib STATIC src/course.cpp
    src/student.cpp)

target_include_directories(GradeCourse_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing() # ctest --output-on-failure
    add_subdirectory(tests)
endif()
