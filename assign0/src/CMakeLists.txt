PROJECT(HelloWorld)

#version to be used
cmake_minimum_required(VERSION 2.8)

# list of src files
set(hello_world_files HelloWorld.cpp)

# define the executable
if (WIN32)
    add_executable(helloWorld WIN32 ${hello_world_files})
else()
    add_executable(helloWorld ${hello_world_files})
endif()

# in Windows + Visual Studio we need this to make it a console application
if(WIN32)
    if(MSVC)
        set_target_properties(helloWorld PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    endif(MSVC)
endif(WIN32)

# install application
set(CMAKE_INSTALL_PREFIX /Users/doggydeng/Desktop/mycode/c++/ENGN2912B/assign0)
set(BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS helloWorld DESTINATION ${BIN_DIR})

