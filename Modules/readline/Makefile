PROJECT_TARGET = readline.out
PROJECT_OBJECTS = readline.o termcap/termcap.o termcap/tgoto.o termcap/tputs.o
ADDED_LIBS = readline/libreadline.a

allsub:
	$(MAKE) -C readline
	$(MAKE) all

include ../../mk/module.mk

