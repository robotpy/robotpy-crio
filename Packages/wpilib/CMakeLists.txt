
# for robotpy.h
include_directories("${PROJECT_BINARY_DIR}")
add_definitions(-D'SVN_REV="${WPILIB_VERSION}"')

file(GLOB_RECURSE WPILIB_SOURCE *.cpp)
add_library(robotpy_wpilib STATIC ${WPILIB_SOURCE})

# regenerate cpp files when sip files change
file(GLOB_RECURSE WPILIB_SIP_SOURCE sip/*.sip)
set(SIP_EXTRA_FILES_DEPEND ${WPILIB_SIP_SOURCE})

ADD_SIP_PYTHON_MODULE(_wpilib sip/wpilibmod.sip robotpy_wpilib)
set(SIP_EXTRA_FILES_DEPEND)

install(DIRECTORY package_wpilib/ DESTINATION "${ROBOTPY_DEST_SITE_PACKAGES}/wpilib")
