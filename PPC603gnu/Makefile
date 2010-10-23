# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/Projects/frc/FIRSTPy
WS_ROOT_DIR := C:/WindRiver/workspace



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/WPILib/CInterfaces -I$(PRJ_ROOT_DIR)/Python/Include -I$(PRJ_ROOT_DIR)/Python -I$(PRJ_ROOT_DIR) 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = FIRSTPy/$(MODE_DIR)/FIRSTPy.out \
	 FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage.o


#Rules

# FIRSTPy
ifeq ($(DEBUG_MODE),1)
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
FIRSTPy/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
FIRSTPy/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/WPILib/CInterfaces -I$(PRJ_ROOT_DIR)/Python/Include -I$(PRJ_ROOT_DIR)/Python -I$(PRJ_ROOT_DIR) 
FIRSTPy/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
FIRSTPy/$(MODE_DIR)/% : PROJECT_TYPE = DKM
FIRSTPy/$(MODE_DIR)/% : DEFINES = 
FIRSTPy/$(MODE_DIR)/% : EXPAND_DBG = 0
FIRSTPy/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
FIRSTPy/$(MODE_DIR)/% : CPU = PPC603
FIRSTPy/$(MODE_DIR)/% : TOOL_FAMILY = gnu
FIRSTPy/$(MODE_DIR)/% : TOOL = gnu
FIRSTPy/$(MODE_DIR)/% : TOOL_PATH = 
FIRSTPy/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
FIRSTPy/$(MODE_DIR)/% : LIBPATH = 
FIRSTPy/$(MODE_DIR)/% : LIBS = 
FIRSTPy/$(MODE_DIR)/% : OBJ_DIR := FIRSTPy/$(MODE_DIR)

OBJECTS_FIRSTPy = FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage.o

FIRSTPy/$(MODE_DIR)/FIRSTPy.out : $(OBJECTS_FIRSTPy)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_FIRSTPy) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_FIRSTPy) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

FIRSTPy/$(MODE_DIR)/FIRSTPy_compile_file : $(FILE) ;

_clean :: FIRSTPy/$(MODE_DIR)/FIRSTPy_clean

FIRSTPy/$(MODE_DIR)/FIRSTPy_clean : 
	$(TRACE_FLAG)if [ -d "FIRSTPy" ]; then cd "FIRSTPy"; rm -rf $(MODE_DIR); fi


# FIRSTPy_partialImage
ifeq ($(DEBUG_MODE),1)
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
FIRSTPy_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
FIRSTPy_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/WPILib/CInterfaces -I$(PRJ_ROOT_DIR)/Python/Include -I$(PRJ_ROOT_DIR)/Python -I$(PRJ_ROOT_DIR) 
FIRSTPy_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
FIRSTPy_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
FIRSTPy_partialImage/$(MODE_DIR)/% : DEFINES = 
FIRSTPy_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
FIRSTPy_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
FIRSTPy_partialImage/$(MODE_DIR)/% : CPU = PPC603
FIRSTPy_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
FIRSTPy_partialImage/$(MODE_DIR)/% : TOOL = gnu
FIRSTPy_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
FIRSTPy_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
FIRSTPy_partialImage/$(MODE_DIR)/% : LIBPATH = 
FIRSTPy_partialImage/$(MODE_DIR)/% : LIBS = 
FIRSTPy_partialImage/$(MODE_DIR)/% : OBJ_DIR := FIRSTPy_partialImage/$(MODE_DIR)

FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/PyRobot.o : C:/Projects/frc/FIRSTPy/PyRobot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_bisectmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_bisectmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_codecsmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_codecsmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_collectionsmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_collectionsmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_csv.o : C:/Projects/frc/FIRSTPy/Python/Modules/_csv.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_elementtree.o : C:/Projects/frc/FIRSTPy/Python/Modules/_elementtree.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_functoolsmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_functoolsmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_heapqmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_heapqmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/_iomodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/_iomodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bufferedio.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/bufferedio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bytesio.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/bytesio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/fileio.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/fileio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/iobase.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/iobase.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/stringio.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/stringio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/textio.o : C:/Projects/frc/FIRSTPy/Python/Modules/_io/textio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_json.o : C:/Projects/frc/FIRSTPy/Python/Modules/_json.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_localemodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_localemodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_pickle.o : C:/Projects/frc/FIRSTPy/Python/Modules/_pickle.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_randommodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_randommodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_sre.o : C:/Projects/frc/FIRSTPy/Python/Modules/_sre.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_struct.o : C:/Projects/frc/FIRSTPy/Python/Modules/_struct.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_testcapimodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_testcapimodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_threadmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/_threadmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_weakref.o : C:/Projects/frc/FIRSTPy/Python/Modules/_weakref.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/arraymodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/arraymodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/atexitmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/atexitmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/binascii.o : C:/Projects/frc/FIRSTPy/Python/Modules/binascii.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/cmathmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/cmathmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/config.o : C:/Projects/frc/FIRSTPy/Python/Modules/config.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/datetimemodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/datetimemodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/errnomodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/errnomodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlparse.o : C:/Projects/frc/FIRSTPy/Python/Modules/expat/xmlparse.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlrole.o : C:/Projects/frc/FIRSTPy/Python/Modules/expat/xmlrole.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmltok.o : C:/Projects/frc/FIRSTPy/Python/Modules/expat/xmltok.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fcntlmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/fcntlmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpectlmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/fpectlmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpetestmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/fpetestmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/gcmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/gcmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getbuildinfo.o : C:/Projects/frc/FIRSTPy/Python/Modules/getbuildinfo.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getpath.o : C:/Projects/frc/FIRSTPy/Python/Modules/getpath.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/itertoolsmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/itertoolsmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mathmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/mathmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/md5module.o : C:/Projects/frc/FIRSTPy/Python/Modules/md5module.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mmapmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/mmapmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/operator.o : C:/Projects/frc/FIRSTPy/Python/Modules/operator.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/parsermodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/parsermodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/pyexpat.o : C:/Projects/frc/FIRSTPy/Python/Modules/pyexpat.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/rotatingtree.o : C:/Projects/frc/FIRSTPy/Python/Modules/rotatingtree.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/selectmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/selectmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha1module.o : C:/Projects/frc/FIRSTPy/Python/Modules/sha1module.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha256module.o : C:/Projects/frc/FIRSTPy/Python/Modules/sha256module.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha512module.o : C:/Projects/frc/FIRSTPy/Python/Modules/sha512module.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/signalmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/signalmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/socketmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/socketmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/symtablemodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/symtablemodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/timemodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/timemodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/unicodedata.o : C:/Projects/frc/FIRSTPy/Python/Modules/unicodedata.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zipimport.o : C:/Projects/frc/FIRSTPy/Python/Modules/zipimport.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/adler32.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/adler32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/compress.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/compress.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/crc32.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/crc32.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/deflate.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/deflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/gzio.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/gzio.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/infback.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/infback.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inffast.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/inffast.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inflate.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/inflate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inftrees.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/inftrees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/trees.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/trees.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/uncompr.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/uncompr.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/zutil.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlib/zutil.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlibmodule.o : C:/Projects/frc/FIRSTPy/Python/Modules/zlibmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/abstract.o : C:/Projects/frc/FIRSTPy/Python/Objects/abstract.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/boolobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/boolobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytearrayobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/bytearrayobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytes_methods.o : C:/Projects/frc/FIRSTPy/Python/Objects/bytes_methods.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytesobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/bytesobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/capsule.o : C:/Projects/frc/FIRSTPy/Python/Objects/capsule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cellobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/cellobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/classobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/classobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/cobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/codeobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/codeobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/complexobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/complexobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/descrobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/descrobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/dictobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/dictobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/enumobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/enumobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/exceptions.o : C:/Projects/frc/FIRSTPy/Python/Objects/exceptions.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/fileobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/fileobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/floatobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/floatobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/frameobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/frameobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/funcobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/funcobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/genobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/genobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/iterobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/iterobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/listobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/listobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/longobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/longobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/memoryobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/memoryobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/methodobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/methodobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/moduleobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/moduleobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/object.o : C:/Projects/frc/FIRSTPy/Python/Objects/object.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/obmalloc.o : C:/Projects/frc/FIRSTPy/Python/Objects/obmalloc.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/rangeobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/rangeobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/setobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/setobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/sliceobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/sliceobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/structseq.o : C:/Projects/frc/FIRSTPy/Python/Objects/structseq.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/tupleobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/tupleobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/typeobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/typeobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodectype.o : C:/Projects/frc/FIRSTPy/Python/Objects/unicodectype.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodeobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/unicodeobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/weakrefobject.o : C:/Projects/frc/FIRSTPy/Python/Objects/weakrefobject.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/acceler.o : C:/Projects/frc/FIRSTPy/Python/Parser/acceler.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/bitset.o : C:/Projects/frc/FIRSTPy/Python/Parser/bitset.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/firstsets.o : C:/Projects/frc/FIRSTPy/Python/Parser/firstsets.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar.o : C:/Projects/frc/FIRSTPy/Python/Parser/grammar.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar1.o : C:/Projects/frc/FIRSTPy/Python/Parser/grammar1.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/listnode.o : C:/Projects/frc/FIRSTPy/Python/Parser/listnode.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/metagrammar.o : C:/Projects/frc/FIRSTPy/Python/Parser/metagrammar.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/myreadline.o : C:/Projects/frc/FIRSTPy/Python/Parser/myreadline.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/node.o : C:/Projects/frc/FIRSTPy/Python/Parser/node.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parser.o : C:/Projects/frc/FIRSTPy/Python/Parser/parser.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parsetok.o : C:/Projects/frc/FIRSTPy/Python/Parser/parsetok.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/pgen.o : C:/Projects/frc/FIRSTPy/Python/Parser/pgen.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/tokenizer.o : C:/Projects/frc/FIRSTPy/Python/Parser/tokenizer.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/Python-ast.o : C:/Projects/frc/FIRSTPy/Python/Python/Python-ast.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/_warnings.o : C:/Projects/frc/FIRSTPy/Python/Python/_warnings.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/asdl.o : C:/Projects/frc/FIRSTPy/Python/Python/asdl.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ast.o : C:/Projects/frc/FIRSTPy/Python/Python/ast.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/bltinmodule.o : C:/Projects/frc/FIRSTPy/Python/Python/bltinmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ceval.o : C:/Projects/frc/FIRSTPy/Python/Python/ceval.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/codecs.o : C:/Projects/frc/FIRSTPy/Python/Python/codecs.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/compile.o : C:/Projects/frc/FIRSTPy/Python/Python/compile.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dtoa.o : C:/Projects/frc/FIRSTPy/Python/Python/dtoa.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dynload_stub.o : C:/Projects/frc/FIRSTPy/Python/Python/dynload_stub.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/errors.o : C:/Projects/frc/FIRSTPy/Python/Python/errors.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/formatter_unicode.o : C:/Projects/frc/FIRSTPy/Python/Python/formatter_unicode.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozen.o : C:/Projects/frc/FIRSTPy/Python/Python/frozen.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozenmain.o : C:/Projects/frc/FIRSTPy/Python/Python/frozenmain.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/future.o : C:/Projects/frc/FIRSTPy/Python/Python/future.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getargs.o : C:/Projects/frc/FIRSTPy/Python/Python/getargs.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcompiler.o : C:/Projects/frc/FIRSTPy/Python/Python/getcompiler.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcopyright.o : C:/Projects/frc/FIRSTPy/Python/Python/getcopyright.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getplatform.o : C:/Projects/frc/FIRSTPy/Python/Python/getplatform.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getversion.o : C:/Projects/frc/FIRSTPy/Python/Python/getversion.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/graminit.o : C:/Projects/frc/FIRSTPy/Python/Python/graminit.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/import.o : C:/Projects/frc/FIRSTPy/Python/Python/import.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/importdl.o : C:/Projects/frc/FIRSTPy/Python/Python/importdl.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/marshal.o : C:/Projects/frc/FIRSTPy/Python/Python/marshal.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/modsupport.o : C:/Projects/frc/FIRSTPy/Python/Python/modsupport.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mysnprintf.o : C:/Projects/frc/FIRSTPy/Python/Python/mysnprintf.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mystrtoul.o : C:/Projects/frc/FIRSTPy/Python/Python/mystrtoul.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/peephole.o : C:/Projects/frc/FIRSTPy/Python/Python/peephole.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyarena.o : C:/Projects/frc/FIRSTPy/Python/Python/pyarena.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyctype.o : C:/Projects/frc/FIRSTPy/Python/Python/pyctype.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyfpe.o : C:/Projects/frc/FIRSTPy/Python/Python/pyfpe.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pymath.o : C:/Projects/frc/FIRSTPy/Python/Python/pymath.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystate.o : C:/Projects/frc/FIRSTPy/Python/Python/pystate.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrcmp.o : C:/Projects/frc/FIRSTPy/Python/Python/pystrcmp.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrtod.o : C:/Projects/frc/FIRSTPy/Python/Python/pystrtod.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pythonrun.o : C:/Projects/frc/FIRSTPy/Python/Python/pythonrun.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/structmember.o : C:/Projects/frc/FIRSTPy/Python/Python/structmember.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/symtable.o : C:/Projects/frc/FIRSTPy/Python/Python/symtable.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/sysmodule.o : C:/Projects/frc/FIRSTPy/Python/Python/sysmodule.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/thread.o : C:/Projects/frc/FIRSTPy/Python/Python/thread.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/traceback.o : C:/Projects/frc/FIRSTPy/Python/Python/traceback.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/wchar.o : C:/Projects/frc/FIRSTPy/wchar.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_FIRSTPy_partialImage = FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/PyRobot.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_bisectmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_codecsmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_collectionsmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_csv.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_elementtree.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_functoolsmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_heapqmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/_iomodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bufferedio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bytesio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/fileio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/iobase.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/stringio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/textio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_json.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_localemodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_pickle.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_randommodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_sre.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_struct.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_testcapimodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_threadmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_weakref.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/arraymodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/atexitmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/binascii.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/cmathmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/config.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/datetimemodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/errnomodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlparse.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlrole.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmltok.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fcntlmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpectlmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpetestmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/gcmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getbuildinfo.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getpath.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/itertoolsmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mathmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/md5module.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mmapmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/operator.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/parsermodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/pyexpat.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/rotatingtree.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/selectmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha1module.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha256module.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha512module.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/signalmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/socketmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/symtablemodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/timemodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/unicodedata.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zipimport.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/adler32.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/compress.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/crc32.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/deflate.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/gzio.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/infback.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inffast.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inflate.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inftrees.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/trees.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/uncompr.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/zutil.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlibmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/abstract.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/boolobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytearrayobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytes_methods.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytesobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/capsule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cellobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/classobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/codeobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/complexobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/descrobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/dictobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/enumobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/exceptions.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/fileobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/floatobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/frameobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/funcobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/genobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/iterobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/listobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/longobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/memoryobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/methodobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/moduleobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/object.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/obmalloc.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/rangeobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/setobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/sliceobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/structseq.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/tupleobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/typeobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodectype.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodeobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/weakrefobject.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/acceler.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/bitset.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/firstsets.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar1.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/listnode.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/metagrammar.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/myreadline.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/node.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parser.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parsetok.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/pgen.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/tokenizer.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/Python-ast.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/_warnings.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/asdl.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ast.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/bltinmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ceval.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/codecs.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/compile.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dtoa.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dynload_stub.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/errors.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/formatter_unicode.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozen.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozenmain.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/future.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getargs.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcompiler.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcopyright.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getplatform.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getversion.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/graminit.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/import.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/importdl.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/marshal.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/modsupport.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mysnprintf.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mystrtoul.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/peephole.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyarena.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyctype.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyfpe.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pymath.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystate.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrcmp.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrtod.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pythonrun.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/structmember.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/symtable.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/sysmodule.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/thread.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/traceback.o \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/wchar.o

FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage.o : $(OBJECTS_FIRSTPy_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_FIRSTPy_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage_compile_file : $(FILE) ;

_clean :: FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage_clean

FIRSTPy_partialImage/$(MODE_DIR)/FIRSTPy_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "FIRSTPy_partialImage" ]; then cd "FIRSTPy_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/PyRobot.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_bisectmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_codecsmodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_collectionsmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_csv.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_elementtree.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_functoolsmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_heapqmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/_iomodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bufferedio.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/bytesio.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/fileio.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/iobase.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/stringio.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_io/textio.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_json.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_localemodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_pickle.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_randommodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_sre.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_struct.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_testcapimodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_threadmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/_weakref.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/arraymodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/atexitmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/binascii.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/cmathmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/config.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/datetimemodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/errnomodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlparse.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmlrole.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/expat/xmltok.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fcntlmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpectlmodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/fpetestmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/gcmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getbuildinfo.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/getpath.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/itertoolsmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mathmodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/md5module.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/mmapmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/operator.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/parsermodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/pyexpat.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/rotatingtree.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/selectmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha1module.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha256module.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/sha512module.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/signalmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/socketmodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/symtablemodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/timemodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/unicodedata.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zipimport.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/adler32.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/compress.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/crc32.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/deflate.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/gzio.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/infback.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inffast.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inflate.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/inftrees.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/trees.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/uncompr.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlib/zutil.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Modules/zlibmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/abstract.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/boolobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytearrayobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytes_methods.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/bytesobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/capsule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cellobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/classobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/cobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/codeobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/complexobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/descrobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/dictobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/enumobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/exceptions.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/fileobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/floatobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/frameobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/funcobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/genobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/iterobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/listobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/longobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/memoryobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/methodobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/moduleobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/object.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/obmalloc.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/rangeobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/setobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/sliceobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/structseq.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/tupleobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/typeobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodectype.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/unicodeobject.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Objects/weakrefobject.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/acceler.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/bitset.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/firstsets.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/grammar1.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/listnode.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/metagrammar.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/myreadline.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/node.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parser.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/parsetok.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/pgen.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Parser/tokenizer.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/Python-ast.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/_warnings.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/asdl.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ast.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/bltinmodule.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/ceval.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/codecs.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/compile.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dtoa.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/dynload_stub.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/errors.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/formatter_unicode.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozen.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/frozenmain.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/future.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getargs.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcompiler.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getcopyright.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getplatform.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/getversion.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/graminit.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/import.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/importdl.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/marshal.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/modsupport.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mysnprintf.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/mystrtoul.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/peephole.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyarena.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyctype.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pyfpe.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pymath.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystate.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrcmp.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pystrtod.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/pythonrun.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/structmember.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/symtable.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/sysmodule.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/thread.d FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/Python/Python/traceback.d \
	 FIRSTPy_partialImage/$(MODE_DIR)/Objects/FIRSTPy/wchar.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
