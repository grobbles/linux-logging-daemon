include_directories(${CMAKE_SOURCE_DIR}/loggingLib/src)

file(GLOB SOURCES "*.cxx" "*.cpp" "*/*.cpp" "*.h" "*.hpp")
file(GLOB HEADER "*.h" "*.hpp")

message(${SOURCES})

add_executable(Client ${SOURCES})

target_link_libraries(Client loggingLib)

# install(TARGETS Client DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})