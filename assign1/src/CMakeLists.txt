PROJECT(Q1-4)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(problem1_file Q1-4.cpp)
set(problem5_file Q5-7.cpp)

# define the executable
if (WIN32)
    add_executable(Q1-4 WIN32 ${problem1_file})
    add_executable(Q5-7 WIN32 ${problem5_file})
else()
    add_executable(Q1-4 ${problem1_file})
    add_executable(Q5-7 ${problem5_file})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(Q1-4 PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
        set_target_properties(Q5-7 PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign1)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS Q1-4 DESTINATION ${BIN_DIR})
install(TARGETS Q5-7 DESTINATION ${BIN_DIR})

