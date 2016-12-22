PROJECT(Matrix)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(matrix_files Matrix.hpp main.cpp)

# define the executable
if (WIN32)
    add_executable(Matrix WIN32 ${matrix_files})
else()
    add_executable(Matrix ${matrix_files})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(Matrix PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign5/src/Q1)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS Matrix DESTINATION ${BIN_DIR})

