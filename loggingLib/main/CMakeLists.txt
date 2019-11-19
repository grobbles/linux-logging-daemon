cmake_minimum_required(VERSION 3.10)

project(${PROJECT_NAME} VERSION 1.1.0 DESCRIPTION "LoggerLib description")
set(MODULE_NAME ${PROJECT_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

set(CMAKE_CXX_FLAGS  -pthread)

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/opt/grpc" "/opt/protobuf")
message("CMAKE_PREFIX_PATH = " ${CMAKE_PREFIX_PATH})

file(GLOB_RECURSE SOURCES "*.cpp")
foreach(file ${SOURCES})
    message("LIB SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp" "*.h")
foreach(file ${HEADER})
    message("LIB HEADER FILE = " ${file})
endforeach()

include_directories(${CMAKE_SOURCE_DIR}/loggingInterfaceLib/main/protoBuf)

add_library(${MODULE_NAME} SHARED ${SOURCES})

# link the exe against the libraries
target_link_libraries(${MODULE_NAME} INTERFACE
    loggingInterfaceLib
)
# set version liblogger.so.1.0.0
set_target_properties(${MODULE_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${MODULE_NAME} PROPERTIES PUBLIC_HEADER "Logger.h")

install(TARGETS ${MODULE_NAME} DESTINATION lib)
install(FILES "Logger.h" DESTINATION include)