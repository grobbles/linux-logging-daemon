set(MODULE_NAME ${PROJECT_NAME})

cmake_minimum_required(VERSION 3.10)
project(${MODULE_NAME})

find_package (Threads)
SET(CMAKE_CXX_FLAGS -pthread)

# file(GLOB SOURCES "*.cxx" "*.cpp" "*/*.cpp" "*/*/*.cpp" "*.h" "*.hpp" "*/*/*.hpp")
# file(GLOB HEADER "*.h" "*.hpp" "*/*.h" "*/*.hpp" "*/*/*.hpp")

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")
message("SOURCES = " ${SOURCES})

file(GLOB_RECURSE HEADER "*.hpp")
message("HEADER = " ${HEADER})

add_executable(${MODULE_NAME} ${SOURCES})

install(TARGETS ${MODULE_NAME} DESTINATION "/usr/bin/" )
