PROJECT(PairsTemplate)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(pairs_files pairs.hpp
     main.cpp)

# define the executable
if (WIN32)
    add_executable(pairs WIN32 ${pairs_files})
else()
    add_executable(pairs ${pairs_files})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(pairs PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign4/Q2)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS pairs DESTINATION ${BIN_DIR})

