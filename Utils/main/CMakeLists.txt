cmake_minimum_required(VERSION 3.10)

project(${PROJECT_NAME} VERSION 1.1.0 DESCRIPTION "LoggerLib description")
set(MODULE_NAME ${PROJECT_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

set(CMAKE_CXX_FLAGS -fPIC)

file(GLOB_RECURSE SOURCES "*.cpp")
foreach(file ${SOURCES})
    message("${MODULE_NAME} LIB SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp" "*.h")
foreach(file ${HEADER})
    message("${MODULE_NAME} LIB HEADER FILE = " ${file})
endforeach()

add_library(${MODULE_NAME} STATIC ${SOURCES})