.PHONY: all

all:
	$(MAKE) -C RobotPy/PPC603gnu
	$(MAKE) -C Modules
	$(MAKE) -C Packages

