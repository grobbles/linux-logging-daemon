set(MODULE_NAME ${PROJECT_NAME}Tests)
project(${MODULE_NAME})
message("")
message("MODULE_NAME --> " ${MODULE_NAME})

set(CMAKE_CXX_FLAGS  -pthread)

file(GLOB SOURCES "main.cpp" "*.cpp" "*/*.cpp"  "../main/Module/*.cpp" "../main/Module/*.hpp")
message("${MODULE_NAME} Sources --> " ${SOURCES})

add_executable(${MODULE_NAME} ${SOURCES})

target_include_directories(${MODULE_NAME} PRIVATE  )

target_link_libraries(${MODULE_NAME}  gtest )



# MACRO(SUBDIRLIST result curdir)
#   FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
#   SET(dirlist "")
#   FOREACH(child ${children})
#     IF(IS_DIRECTORY ${curdir}/${child})
#       LIST(APPEND dirlist ${child})
#     ENDIF()
#   ENDFOREACH()
#   SET(${result} ${dirlist})
# ENDMACRO()

# macro(list_subdirectories return_value curdir return_relative)
#   file(GLOB sub-dir RELATIVE ${curdir} *)
#   set(list_of_dirs "")
#   foreach(dir ${sub-dir})
#     if(IS_DIRECTORY ${curdir}/${dir})
#       if (${return_relative})
#         set(list_of_dirs ${list_of_dirs} ${dir})
#       else()
#         set(list_of_dirs ${list_of_dirs} ${curdir}/${dir})
#       endif()
#     endif()
#   endforeach()
#   set(${return_value} ${list_of_dirs})
# endmacro()