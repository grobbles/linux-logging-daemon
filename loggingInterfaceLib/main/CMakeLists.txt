set(MODULE_NAME ${PROJECT_NAME})
project(${MODULE_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread")

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/opt/grpc" "/opt/protobuf")
message("CMAKE_PREFIX_PATH = " ${CMAKE_PREFIX_PATH})

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/grpc/")
message("CMAKE_MODULE_PATH = " ${CMAKE_MODULE_PATH})

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

file(GLOB_RECURSE PROTOS "*.proto")
message ("PROTOS = ${PROTOS}")


# set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/protoBufSrc)
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protoBuf)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES ${GRPC_SRCS} ${GRPC_HDRS} ${PROTO_SRCS} ${PROTO_HDRS})
foreach(file ${SOURCES})
    message("${MODULE_NAME} SOURCES FILE = " ${file})
endforeach()

set(HEADER ${GRPC_HDRS} ${PROTO_HDRS})
foreach(file ${HEADERS})
    message("${MODULE_NAME} HEADERS FILE = " ${file})
endforeach()

add_library(${MODULE_NAME} STATIC ${SOURCES})
target_include_directories(${MODULE_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${MODULE_NAME}
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROTO_SRC_DIR}
)

# link the exe against the libraries
target_link_libraries(${MODULE_NAME} PUBLIC
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)
