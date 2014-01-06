
# version strings are always YEAR.VERSION, with git information
# sometimes appended to them

include(GetGitRevisionDescription)
git_describe(ROBOTPY_VERSION ${CMAKE_CURRENT_SOURCE_DIR} --tags --dirty=-dirty)
git_describe(WPILIB_VERSION ${CMAKE_CURRENT_SOURCE_DIR}/Packages/wpilib/WPILib --tags --dirty=-dirty)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" ROBOTPY_VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" ROBOTPY_VERSION_MINOR "${VERSION}")

message("RobotPy version: ${ROBOTPY_VERSION}")
message("WPILib version : ${WPILIB_VERSION}")

configure_file (
  "${PROJECT_SOURCE_DIR}/RobotPy.h.in"
  "${PROJECT_BINARY_DIR}/RobotPy.h"
)

