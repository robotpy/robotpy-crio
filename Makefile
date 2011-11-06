SUBDIRS =
SUBDIRS += RobotPy
SUBDIRS += Modules
SUBDIRS += Packages

.PHONY: all clean dist pre-dist do-dist post-dist $(SUBDIRS) VERSION-FILE.h

all: $(SUBDIRS)

$(SUBDIRS): VERSION-FILE.h
	@$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	@$(MAKE) -C $* clean

VERSION-FILE.h:
	cmd /c VERSION-GEN.bat

dist: pre-dist do-dist post-dist

do-dist:: $(addsuffix -dist,$(SUBDIRS))
%-dist::
	@$(MAKE) -C $* DISTDIR=$(DISTDIR) dist

pre-dist:
	$(eval version := $(shell cat VERSION-FILE))
	$(eval DISTDIR := $(CURDIR)/RobotPy-$(version))
	@echo $(DISTDIR)
	-rm -rf $(DISTDIR)
	-mkdir $(DISTDIR)

	# Build distribution directories
	-mkdir -p $(DISTDIR)/robot/ni-rt/system
	-mkdir -p $(DISTDIR)/robot/lib/python3.2/lib-dynload
	-mkdir -p $(DISTDIR)/robot/lib/python3.2/site-packages

post-dist:
	cp README-Dist.txt $(DISTDIR)/README.txt
	cp -R py $(DISTDIR)/robot/py
	cp -R utilities $(DISTDIR)/
	cp -R samples $(DISTDIR)/

	# Include the installer at the top level
	cp utilities/installer/install.py $(DISTDIR)

	# Zip it up
	zip -r -9 -q RobotPy-$(version).zip RobotPy-$(version)
