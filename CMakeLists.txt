cmake_minimum_required(VERSION 3.20)

project(GradeBook VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")
add_library(GradeBook_lib STATIC ${SOURCES})
target_include_directories(GradeBook_lib PUBLIC ${CMAKE_CURRENT_SOURCES_DIR}/include)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
