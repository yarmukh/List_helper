cmake_minimum_required(VERSION 3.20)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

# Явно указываем путь к PDCurses в MSYS2
set(PDCURSES_ROOT "C:/msys64/mingw64")
find_library(PDCURSES_LIBRARY
        NAMES pdcurses curses
        PATHS "${PDCURSES_ROOT}/lib"
        REQUIRED
)

find_path(PDCURSES_INCLUDE_DIR
        NAMES curses.h
        PATHS "${PDCURSES_ROOT}/include"
        REQUIRED
)

message(STATUS "PDCurses library: ${PDCURSES_LIBRARY}")
message(STATUS "PDCurses includes: ${PDCURSES_INCLUDE_DIR}")

add_executable(
        ToDoList
        sources/main.cpp
        sources/Notebook.cpp
        headers/Note.h
        headers/Notebook.h
        headers/View.h
        sources/View.cpp
        sources/Storage.cpp
        headers/Storage.h
)

target_include_directories(ToDoList PRIVATE ${PDCURSES_INCLUDE_DIR})
target_link_libraries(ToDoList ${PDCURSES_LIBRARY})