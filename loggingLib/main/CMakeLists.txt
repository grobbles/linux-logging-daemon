project(${PROJECT_NAME} VERSION 1.1.0 DESCRIPTION "loggingLib description")
set(MODULE_NAME ${PROJECT_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

set(CMAKE_CXX_FLAGS  -fPIC)

file(GLOB_RECURSE SOURCES "*.cpp")
foreach(file ${SOURCES})
    message("${MODULE_NAME} LIB SOURCE FILE = " ${file})
endforeach()

file(GLOB_RECURSE HEADER "*.hpp" "*.h")
foreach(file ${HEADER})
    message("${MODULE_NAME} LIB HEADER FILE = " ${file})
endforeach()

add_library(${MODULE_NAME} SHARED ${SOURCES})
target_include_directories(${MODULE_NAME} PUBLIC ${PROJECT_DIRECTORY}/main)

include_directories(${CMAKE_SOURCE_DIR}/loggingInterfaceLib/main)
include_directories(${CMAKE_SOURCE_DIR}/Utils/main)
target_link_libraries(${MODULE_NAME} PUBLIC
    loggingInterfaceLib
    Utils
)

set_target_properties(${MODULE_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${MODULE_NAME} PROPERTIES PUBLIC_HEADER "Logger.h")

install(TARGETS ${MODULE_NAME} DESTINATION lib)
install(FILES "Logger.h" DESTINATION include)