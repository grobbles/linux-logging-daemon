cmake_minimum_required(VERSION 3.10)
project (Utils)
message("")
message("PROJECT_NAME = " ${PROJECT_NAME})

set(PROJECT_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})
message("PROJECT_DIRECTORY = " ${PROJECT_DIRECTORY})

set(CMAKE_INSTALL_PREFIX ${PROJECT_DIRECTORY})
message("CMAKE_INSTALL_PREFIX = " ${CMAKE_INSTALL_PREFIX})

add_subdirectory(main)
# add_subdirectory(tests)