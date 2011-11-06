SUBDIRS =
SUBDIRS += sip
SUBDIRS += nivision
SUBDIRS += vision
SUBDIRS += vision2009
SUBDIRS += wpilib

.PHONY: all clean dist $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	@$(MAKE) -C $* clean

dist:: $(addsuffix -dist,$(SUBDIRS))
%-dist::
	@$(MAKE) -C $* DISTDIR=$(DISTDIR)/robot/lib/python3.2/site-packages dist
