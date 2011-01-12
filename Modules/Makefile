.PHONY: all clean

DIRS = \
	_bisect \
	_collections \
	_csv \
	_elementtree \
	_heapq \
	_md5 \
	_pickle \
	_random \
	_sha1 \
	_sha256 \
	_sha512 \
	_socket \
	_struct \
	array \
	atexit \
	binascii \
	cmath \
	datetime \
	fcntl \
	fpectl \
	itertools \
	math \
	operator \
	parser \
	pyexpat \
	readline \
	select \
	time \
	unicodedata \
	zlib
	
all:
	-for d in $(DIRS); do $(MAKE) -C $$d; done
	
clean:
	-for d in $(DIRS); do $(MAKE) -C $$d clean; done


