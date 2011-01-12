SUBDIRS =
SUBDIRS += RobotPy
SUBDIRS += Modules
SUBDIRS += Packages

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	$(MAKE) -C $* clean
