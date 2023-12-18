cmake_minimum_required(VERSION 3.27)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab3
        src/main.cpp
        src/task.h
        src/task.h
        src/task1.cpp
        src/task2.cpp
        src/task3.cpp
        src/task4.cpp
)

add_executable(Lab3_example
        src_example/CHMlab3.cpp
        src_example/Gauss.cpp
        src_example/Gauss.h
        src_example/Khaletski.cpp
        src_example/Khaletski.h
        src_example/LU.cpp
        src_example/LU.h
)