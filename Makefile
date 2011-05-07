SUBDIRS =
SUBDIRS += RobotPy
SUBDIRS += Modules
SUBDIRS += Packages

.PHONY: all clean $(SUBDIRS) VERSION-FILE.h

all: $(SUBDIRS)

$(SUBDIRS): VERSION-FILE.h
	$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	$(MAKE) -C $* clean

VERSION-FILE.h:
	cmd /c VERSION-GEN.bat
