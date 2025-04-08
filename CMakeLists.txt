cmake_minimum_required(VERSION 3.22)

project(ToDoList VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    ToDoList
    sources/main.cpp
    sources/Notebook.cpp
    headers/Note.h
    headers/Notebook.h
)