.PHONY: all clean dist

all:
	$(MAKE) -C PPC603gnu DEBUG_MODE=0

clean:
	-cd PPC603gnu && $(MAKE) clean DEBUG_MODE=0

dist: all
	cp -R Python/Lib/* $(DISTDIR)/robot/lib/python3.2/
	cp PPC603gnu/RobotPy/NonDebug/RobotPy.out $(DISTDIR)/robot/ni-rt/system/

