.PHONY: all clean

all:
	$(MAKE) -C RobotPy/PPC603gnu DEBUG_MODE=0
	$(MAKE) -C Modules
	$(MAKE) -C Packages
	
clean:
	-cd RobotPy/PPC603gnu && $(MAKE) clean DEBUG_MODE=0
	$(MAKE) -C Modules clean
	$(MAKE) -C Packages clean

