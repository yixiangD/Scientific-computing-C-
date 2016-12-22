PROJECT(AbstractODE)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(abode_files ForwardEulerSolver.hpp ForwardEulerSolver.cpp RungeKuttaSolver.hpp RungeKuttaSolver.cpp AbstractOdeSolver.hpp main.cpp)

# define the executable
if (WIN32)
    add_executable(AbOde WIN32 ${abode_files})
else()
    add_executable(AbOde ${abode_files})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(AbOde PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign3/Q2)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS AbOde DESTINATION ${BIN_DIR})

