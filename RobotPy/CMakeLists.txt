
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB_RECURSE SOURCE_CODE *.c *.cpp)
add_executable(RobotPy.out ${SOURCE_CODE})

install(TARGETS RobotPy.out DESTINATION "${ROBOTPY_DEST_EXE}")
install(DIRECTORY Python/Lib/ DESTINATION "${ROBOTPY_DEST_PYLIB}")
