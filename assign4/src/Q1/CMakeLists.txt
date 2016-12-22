PROJECT(Strstreamfile)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(work_files main.cpp)

# define the executable
if (WIN32)
    add_executable(Strstreamfile WIN32 ${work_files})
else()
    add_executable(Strstreamfile ${work_files})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(Strstreamfile PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign4/src/Q1)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS Strstreamfile DESTINATION ${BIN_DIR})

