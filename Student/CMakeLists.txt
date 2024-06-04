cmake_minimum_required(VERSION 3.26)
project(Student)

set(CMAKE_CXX_STANDARD 14)

add_executable(Student
        main.cpp
        sortedbyGPA.txt
        sortedbyname.txt
        Students.txt)
