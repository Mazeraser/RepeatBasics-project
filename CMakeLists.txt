cmake_minimum_required(VERSION 3.31)
project(Basics_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Basics_project main.cpp
        task.h
        task.cpp
        taskManager.h
        taskManager.cpp)
