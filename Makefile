.PHONY: all

all:
	$(MAKE) -C RobotPy/PPC603gnu DEBUG_MODE=0
	$(MAKE) -C Modules
	$(MAKE) -C Packages

