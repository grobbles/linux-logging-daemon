cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME ${PROJECT_NAME}Tests)
message("")
message("MODULE_NAME --> " ${MODULE_NAME})
project(${MODULE_NAME})

set(CMAKE_CXX_FLAGS  -pthread)

file(GLOB_RECURSE SOURCES "*.cpp" "../*.cpp")
foreach(file ${SOURCES})
    message("LIB TEST SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp" "*.h" "../*.hpp" "../*.h")
foreach(file ${HEADER})
    message("LIB TEST HEADER FILE = " ${file})
endforeach()

add_executable(${MODULE_NAME} ${SOURCES})

target_include_directories(${MODULE_NAME} PRIVATE  ../src/Logging/)

target_link_libraries(${MODULE_NAME}  gtest)
