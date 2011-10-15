SUBDIRS =
SUBDIRS += RobotPy
SUBDIRS += Modules
SUBDIRS += Packages

.PHONY: all clean dist $(SUBDIRS) VERSION-FILE.h

all: $(SUBDIRS)

$(SUBDIRS): VERSION-FILE.h
	$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	$(MAKE) -C $* clean

VERSION-FILE.h:
	cmd /c VERSION-GEN.bat

dist: all
	$(eval version := $(shell cat VERSION-FILE))
	$(eval dist := dist-$(version))
	@echo $(dist)
	-rm -rf $(dist)
	-mkdir $(dist)

	# RobotPy-Core distribution
	-mkdir -p $(dist)/RobotPy-Core/robot/ni-rt/system
	-mkdir -p $(dist)/RobotPy-Core/robot/lib/python3.2/lib-dynload
	-mkdir -p $(dist)/RobotPy-Core/robot/lib/python3.2/site-packages

	cp README-Core.txt $(dist)/RobotPy-Core/
	cp -R py $(dist)/RobotPy-Core/robot/py
	cp -R RobotPy/Python/Lib/* $(dist)/RobotPy-Core/robot/lib/python3.2/
	cp RobotPy/PPC603gnu/RobotPy/NonDebug/RobotPy.out $(dist)/RobotPy-Core/robot/ni-rt/system/FRC_UserProgram.out

	cp Modules/*/*.out $(dist)/RobotPy-Core/robot/lib/python3.2/lib-dynload

	cp Packages/sip/*.out $(dist)/RobotPy-Core/robot/lib/python3.2/site-packages

	# RobotPy-WPILib distribution
	$(eval sitepackages := $(dist)/RobotPy-WPILib/robot/lib/python3.2/site-packages)
	-mkdir -p $(sitepackages)

	cp README-WPILib.txt $(dist)/RobotPy-WPILib/

	cp -R samples $(dist)/RobotPy-WPILib/samples

	cp Packages/wpilib/*.out $(sitepackages)
	cp Packages/wpilib/*.py $(sitepackages)

	cp Packages/nivision/*.out $(sitepackages)
	cp Packages/nivision/*.py $(sitepackages)

	cp Packages/vision/*.out $(sitepackages)
	cp Packages/vision/*.py $(sitepackages)

	cp Packages/vision2009/*.out $(sitepackages)
	cp Packages/vision2009/*.py $(sitepackages)

	# RobotPy-Utilities distribution
	cp -R utilities $(dist)/RobotPy-Utilities

	# RobotPy distribution (everything)
	-mkdir $(dist)/RobotPy
	cp -R $(dist)/RobotPy-Core/* $(dist)/RobotPy/
	cp -R $(dist)/RobotPy-WPILib/* $(dist)/RobotPy/
	cp -R $(dist)/RobotPy-Utilities/* $(dist)/RobotPy/

	# Include the installer with the dist
	cp utilities/installer/install.py $(dist)/RobotPy-Core
	cp utilities/installer/install.py $(dist)/RobotPy-WPILib
	cp utilities/installer/install.py $(dist)/RobotPy

	# Zip it up
	cd $(dist) && zip -r -9 -q RobotPy-Core-$(version).zip RobotPy-Core 
	cd $(dist) && zip -r -9 -q RobotPy-WPILib-$(version).zip RobotPy-WPILib
	cd $(dist) && zip -r -9 -q RobotPy-Utilities-$(version).zip RobotPy-Utilities
	cd $(dist) && zip -r -9 -q RobotPy-$(version).zip RobotPy
