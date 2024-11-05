cmake_minimum_required(VERSION 3.29)
project(P2)

set(CMAKE_CXX_STANDARD 20)

add_executable(P2 main.cpp
        Student.h
        Student.cpp
        cmake-build-debug/student.txt
        Status.cpp
        Status.h
        Date.cpp
        Date.h)
