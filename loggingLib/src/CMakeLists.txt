cmake_minimum_required(VERSION 3.10)

project(LoggingLib VERSION 1.1.0 DESCRIPTION "LoggerLib description")

set(libName logger)

file(GLOB libSrcs "*.cpp" "*.h" "*.hpp")
file(GLOB libHeader "*.h" "*.hpp")

add_library(${libName} SHARED ${libSrcs})

# set version liblogger.so.1.0.0
set_target_properties(${libName} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${libName} PROPERTIES PUBLIC_HEADER "Logger.h")

install(TARGETS ${libName} DESTINATION lib)
install(FILES "Logger.h" DESTINATION include)