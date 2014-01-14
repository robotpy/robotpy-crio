
include_directories("${PROJECT_BINARY_DIR}")

add_subdirectory("ext")

include(PythonFiles.cmake)
add_executable(RobotPy.out ${PY_SOURCE_CODE})

# static modules 

install(TARGETS RobotPy.out DESTINATION "${ROBOTPY_DEST_EXE}")
install(DIRECTORY Python/Lib/ DESTINATION "${ROBOTPY_DEST_PYLIB}")

# dynamic modules

MACRO(ADD_ROBOTPY_MODULE MODULE_NAME)
	
	set(MOD_SRC)
	foreach(arg ${ARGN})
		list(APPEND MOD_SRC "Python/Modules/${arg}") 
	endforeach()
	
	add_executable(${MODULE_NAME}.pyd ${MOD_SRC})
	install(TARGETS ${MODULE_NAME}.pyd DESTINATION robot/lib/python3.2/lib-dynload)

ENDMACRO(ADD_ROBOTPY_MODULE)

include_directories("ext")

# TODO: pyexpat & readline are currently broken

ADD_ROBOTPY_MODULE(_bisect _bisectmodule.c)
ADD_ROBOTPY_MODULE(_csv _csv.c)
ADD_ROBOTPY_MODULE(_datetime _datetimemodule.c _time.c)
#ADD_ROBOTPY_MODULE(_elementtree _elementtree.c)
ADD_ROBOTPY_MODULE(_heapq _heapqmodule.c)
ADD_ROBOTPY_MODULE(_md5 md5module.c)
ADD_ROBOTPY_MODULE(_pickle _pickle.c)
#ADD_ROBOTPY_MODULE(_pyexpat pyexpat.c)
ADD_ROBOTPY_MODULE(_random _randommodule.c)
ADD_ROBOTPY_MODULE(_sha1 sha1module.c)
ADD_ROBOTPY_MODULE(_sha256 sha256module.c)
ADD_ROBOTPY_MODULE(_sha512 sha512module.c)
ADD_ROBOTPY_MODULE(_socket socketmodule.c)
ADD_ROBOTPY_MODULE(_struct _struct.c)
ADD_ROBOTPY_MODULE(array arraymodule.c)
ADD_ROBOTPY_MODULE(atexit atexitmodule.c)
ADD_ROBOTPY_MODULE(binascii binascii.c)
ADD_ROBOTPY_MODULE(cmath cmathmodule.c _math.c)
ADD_ROBOTPY_MODULE(fcntl fcntlmodule.c)
ADD_ROBOTPY_MODULE(fpectl fpectlmodule.c)
ADD_ROBOTPY_MODULE(math _math.c mathmodule.c)
ADD_ROBOTPY_MODULE(parser parsermodule.c)
#ADD_ROBOTPY_MODULE(pyexpat pyexpat.c expat/xmlparse.c expat/xmlrole.c expat/xmltok.c)
#ADD_ROBOTPY_MODULE(readline readline.c) # need ext
ADD_ROBOTPY_MODULE(select selectmodule.c)
ADD_ROBOTPY_MODULE(time _time.c timemodule.c)
ADD_ROBOTPY_MODULE(unicodedata unicodedata.c)
ADD_ROBOTPY_MODULE(zlib zlibmodule.c)

#target_link_libraries(readline.pyd RobotPy_extern) 
