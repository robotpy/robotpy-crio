
file(GLOB_RECURSE SOURCE_CODE *.c *.cpp)
add_executable(sip.pyd ${SOURCE_CODE})

install(TARGETS sip.pyd DESTINATION "${ROBOTPY_DEST_SITE_PACKAGES}")
