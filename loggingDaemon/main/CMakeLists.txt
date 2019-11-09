set(MODULE_NAME ${PROJECT_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

cmake_minimum_required(VERSION 3.10)
project(${MODULE_NAME})

find_package (Threads)
SET(CMAKE_CXX_FLAGS -pthread)

file(GLOB_RECURSE SOURCES "*.cpp")
foreach(file ${SOURCES})
    message("MAIN SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp")
foreach(file ${HEADER})
    message("MAIN HEADER FILE = " ${file})
endforeach()

add_executable(${MODULE_NAME} ${SOURCES} ${SOURCES})

install(TARGETS ${MODULE_NAME} DESTINATION "/usr/bin/" )
