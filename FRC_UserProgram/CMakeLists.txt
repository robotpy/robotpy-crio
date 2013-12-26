
add_executable(FRC_UserProgram.out FRC_UserProgram.cpp)

install(TARGETS FRC_UserProgram.out DESTINATION robot/ni-rt/system)
