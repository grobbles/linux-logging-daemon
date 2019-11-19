cmake_minimum_required (VERSION 3.10)
# project (loggingDaemon)

# Version Definition  #####################################################
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# Package Generator  #######################################################
SET(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_DESCRIPTION "A logging daemon example")
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Uwe Roder")
set(CPACK_PACKAGE_VENDOR "UWE_RODER")
set(CPACK_PACKAGE_CONTACT "uweroder@gmail.com")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "/usr/bin")
include (CPack)

set(PROJECT_INSTALL_LIB_DIR "${CMAKE_CURRENT_BINARY_DIR}/projectLib/lib")
set(PROJECT_INCLUDE_DIRECTOIES "${CMAKE_CURRENT_BINARY_DIR}/projectLib/include")
set(PROJECT_GENERAOR_DIR "${CMAKE_CURRENT_BINARY_DIR}/generaor/")



# Modules  #################################################################
add_subdirectory(loggingDaemon)
add_subdirectory(loggingLib)
add_subdirectory(Client)
add_subdirectory(loggingInterfaceLib)
# add_subdirectory(gprcLogInterface)
# add_subdirectory(CMakeExecutableTemplate)

