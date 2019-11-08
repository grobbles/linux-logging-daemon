set(MODULE_NAME ${PROJECT_NAME}Tests)

cmake_minimum_required(VERSION 3.10)
project(${MODULE_NAME})

set(CMAKE_CXX_FLAGS  -pthread)

file(GLOB_RECURSE SOURCES "main.cpp" "*.cpp" "*.hpp" "main/*/*.cpp" "../main/*/*.hpp"  "../main/*/*.cpp" "../main/*/*/*.hpp"  "../main/*/*/*.cpp") 
message("test SOURCES = " ${SOURCES})

message(${SOURCES})
add_executable(${MODULE_NAME} ${SOURCES})
target_include_directories(${MODULE_NAME} PRIVATE  ../main/Utils/Logging/ ../main/Utils/ArgumentParser/ ../main/Utils/DirectoryUtils)

target_link_libraries(${MODULE_NAME}  gtest)

cmake_minimum_required(VERSION 3.2)