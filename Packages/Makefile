SUBDIRS =
SUBDIRS += sip
SUBDIRS += nivision
SUBDIRS += vision
SUBDIRS += vision2009
SUBDIRS += wpilib

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	$(MAKE) -C $* clean
