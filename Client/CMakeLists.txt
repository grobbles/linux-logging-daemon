set(MODULE_NAME Client)
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES "*.cpp")
foreach(file ${SOURCES})
    message("${MODULE_NAME} SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp" "*.h")
foreach(file ${HEADER})
    message("${MODULE_NAME} HEADER FILE = " ${file})
endforeach()

add_executable(Client ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/loggingLib/main)
include_directories(${CMAKE_SOURCE_DIR}/Utils/main)

target_link_libraries(Client Utils Logging)
