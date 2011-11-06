SUBDIRS =
SUBDIRS += _bisect
SUBDIRS += _csv
SUBDIRS += _datetime
SUBDIRS += _elementtree
SUBDIRS += _heapq
SUBDIRS += _md5
SUBDIRS += _pickle
SUBDIRS += _random
SUBDIRS += _sha1
SUBDIRS += _sha256
SUBDIRS += _sha512
SUBDIRS += _socket
SUBDIRS += _struct
SUBDIRS += array
SUBDIRS += atexit
SUBDIRS += binascii
SUBDIRS += cmath
SUBDIRS += fcntl
SUBDIRS += fpectl
SUBDIRS += math
SUBDIRS += parser
SUBDIRS += pyexpat
SUBDIRS += readline
SUBDIRS += select
SUBDIRS += time
SUBDIRS += unicodedata
SUBDIRS += zlib

.PHONY: all clean dist $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:: $(addsuffix -clean,$(SUBDIRS))
%-clean::
	@$(MAKE) -C $* clean

dist:: $(addsuffix -dist,$(SUBDIRS))
%-dist::
	@$(MAKE) -C $* DISTDIR=$(DISTDIR)/robot/lib/python3.2/lib-dynload dist
