
file(GLOB SOURCE_CODE *.c)
get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
add_executable(${MODULE_NAME}.pyd ${SOURCE_CODE})

install(TARGETS ${MODULE_NAME}.pyd DESTINATION robot/lib/python3.2/lib-dynload)