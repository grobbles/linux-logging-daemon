set(MODULE_NAME ${PROJECT_NAME})
project(${MODULE_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/opt/grpc" "/opt/protobuf")
message("CMAKE_PREFIX_PATH = " ${CMAKE_PREFIX_PATH})

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/grpc/")
message("CMAKE_MODULE_PATH = " ${CMAKE_MODULE_PATH})

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

file(GLOB_RECURSE PROTOS "*.proto")
message ("PROTOS = ${PROTOS}")

set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LoggingClientInterface/GRPC/LogMessageTransporterServiceImpl/protoBuf)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread")

file(GLOB_RECURSE SOURCES "main.cpp" "*.cpp" "*.cc")
set(SOURCES ${SOURCES} ${HEADER} ${GRPC_SRCS} ${GRPC_HDRS} ${PROTO_SRCS} ${PROTO_HDRS})
foreach(file ${SOURCES})
    message("${MODULE_NAME} SOURCES FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADERS "*.hpp" "*.h")
set(HEADER ${HEADER} ${HEADER}  ${GRPC_HDRS} ${PROTO_HDRS})
foreach(file ${HEADERS})
    message("${MODULE_NAME} HEADERS FILE = " ${file})
endforeach()

# Tell CMake to create the helloworld executable
add_executable(${MODULE_NAME} ${SOURCES})

# target_link_libraries( ${MODULE_NAME} PRIVATE GrpcLogInterface )

# link the exe against the libraries
target_link_libraries(${MODULE_NAME} 
    PUBLIC
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)


# cmake_minimum_required(VERSION 3.10)

# set(MODULE_NAME ${PROJECT_NAME})
# message("")
# message("MODULE_NAME --> " ${MODULE_NAME})
# project(${MODULE_NAME})

# # Find includes in the build directories
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# find_package (Threads)
# SET(CMAKE_CXX_FLAGS -pthread)

# file(GLOB_RECURSE SOURCES "*.cpp" "*.cc")
# foreach(file ${SOURCES})
#     message("MAIN SOURCE FILE = " ${file})
# endforeach()

# file(GLOB_RECURSE HEADER "*.hpp" "*.h")
# foreach(file ${HEADER})
#     message("MAIN HEADER FILE = " ${file})
# endforeach()

# add_executable(${MODULE_NAME} ${SOURCES})

# target_link_libraries( ${MODULE_NAME} PRIVATE GrpcLogInterface)

# install(TARGETS ${MODULE_NAME} DESTINATION "/usr/bin/")
