set(MODULE_NAME ${PROJECT_NAME})
project(${MODULE_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread")

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/opt/grpc" "/opt/protobuf")
message("CMAKE_PREFIX_PATH = " ${CMAKE_PREFIX_PATH})

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES "main.cpp" "*.cpp" "*.cc")
foreach(file ${SOURCES})
    message("${MODULE_NAME} SOURCES FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADERS "*.hpp" "*.h")
foreach(file ${HEADERS})
    message("${MODULE_NAME} HEADERS FILE = " ${file})
endforeach()

# Tell CMake to create the helloworld executable
add_executable(${MODULE_NAME} ${SOURCES} ${HEADERS})


include_directories(${CMAKE_SOURCE_DIR}/loggingInterfaceLib/main)
include_directories(${CMAKE_SOURCE_DIR}/Utils/main)

# link the exe against the libraries
target_link_libraries(${MODULE_NAME} PUBLIC
    loggingInterfaceLib
    Utils
)