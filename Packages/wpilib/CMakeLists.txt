
add_definitions(-D'SVN_REV="${WPILIB_VERSION}"')

file(GLOB_RECURSE WPILIB_SOURCE *.cpp)
add_library(robotpy_wpilib STATIC ${WPILIB_SOURCE})

ADD_SIP_PYTHON_MODULE(_wpilib sip/wpilibmod.sip robotpy_wpilib)

install(DIRECTORY package_wpilib/ DESTINATION "${ROBOTPY_DEST_SITE_PACKAGES}/wpilib")
