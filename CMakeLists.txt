
# haven't tested with other versions, but 2.8.7 works
cmake_minimum_required(VERSION 2.8.7)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(CMAKE_BUILD_TYPE "Release")

project("RobotPy")

include(RobotpyVersion)
include(RobotLayout)

#
# Setup SIP (the version number for sip.exe must match exactly, because we include
# the SIP python module source in our build tree)
#

find_package(PythonInterp REQUIRED)
find_package(SIP 4.15.3 EXACT REQUIRED)

include(SIPMacros)
set(SIP_INCLUDES .)
set(SIP_EXTRA_OPTIONS -g)

#
# Setup packaging
#

include(CPackConfig)
include(CPack)

#
# Ensure that 'make install' copies all files to the build directory, since
# the user shouldn't actually install these files...  
#

SET(ROBOTPY_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/dist" CACHE PATH "Installation directory")
SET(CMAKE_INSTALL_PREFIX "${ROBOTPY_INSTALL_PREFIX}" CACHE INTERNAL "Prefix prepended to install directories" FORCE)

#
# Setup include directories for everything
#

include_directories(RobotPy/Python RobotPy/Python/Include)
include_directories(Packages/wpilib Packages/wpilib/WPILib)

#
# Compile stuff
#

add_subdirectory("FRC_UserProgram")
add_subdirectory("Modules")
add_subdirectory("Packages")
add_subdirectory("RobotPy")

#
# Install extra files for dist
# 

install(FILES README-Dist.txt RENAME README.txt DESTINATION .)
install(PROGRAMS utilities/installer/install.py DESTINATION .)

install(DIRECTORY py DESTINATION "${ROBOTPY_DEST_ROOT}")
install(DIRECTORY utilities DESTINATION .)
install(DIRECTORY samples DESTINATION .)

#
# Final warning
#

if("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}")
  message(WARNING "The source directory is the same as binary directory. \"make clean\" may damage the source tree")
endif()
