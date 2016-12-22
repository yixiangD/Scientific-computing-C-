PROJECT(Q1-2)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(problem1_file Q1.cpp)
set(problem2_file Q2.cpp)

# define the executable
if (WIN32)
    add_executable(Q1 WIN32 ${problem1_file})
    add_executable(Q2 WIN32 ${problem2_file})
else()
    add_executable(Q1 ${problem1_file})
    add_executable(Q2 ${problem2_file})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(Q1 PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
        set_target_properties(Q2 PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign2)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS Q1 DESTINATION ${BIN_DIR})
install(TARGETS Q2 DESTINATION ${BIN_DIR})

