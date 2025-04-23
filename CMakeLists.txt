#cmake_minimum_required(VERSION 3.22)
#
#project(ToDoList VERSION 0.1 LANGUAGES CXX)
#
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
#
#find_package(Curses REQUIRED)
#if(CURSES_FOUND)
#    add_executable(
#            ToDoList
#            sources/main.cpp
#            sources/Notebook.cpp
#            headers/Note.h
#            headers/Notebook.h
#            headers/ClearScreen.h
#
#    )
#    target_link_libraries(ToDoList ${CURSES_LIBRARIES} pdcurses)
#else()
#    message(FATAL_ERROR "Curses library not found")
#endif()


#find_package(Curses REQUIRED)

#include_directories(${CURSES_INCLUDE_DIRS})


#add_executable(ToDoList sources/main.cpp sources/Notebook.cpp)
#target_link_libraries(ToDoList pdcurses)



#target_link_libraries(ToDoList ${CURSES_LIBRARIES})
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
        headers/ClearScreen.h
)

target_include_directories(ToDoList PRIVATE ${PDCURSES_INCLUDE_DIR})
target_link_libraries(ToDoList ${PDCURSES_LIBRARY})
