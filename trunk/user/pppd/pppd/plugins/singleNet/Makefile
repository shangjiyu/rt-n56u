#***********************************************************************
#
# Makefile
#
# This program may be distributed according to the terms of the GNU
# General Public License, version 2 or (at your option) any later version.
#
# $Id: Makefile,v 1.1.1.1 2016/05/01 12:14:18 shangjiyu $
#***********************************************************************

DESTDIR = $(INSTROOT)/usr
LIBDIR = $(DESTDIR)/lib/pppd/$(PPPDVERSION)

PPPDVERSION = $(shell awk -F '"' '/VERSION/ { print $$2; }' ../../patchlevel.h)

INSTALL	= install

# Version is set ONLY IN THE MAKEFILE!  Don't delete this!
PLUGINVERSION=2

COPTS=-O2 -g
CFLAGS = $(COPTS) -I. -I../.. -I../../.. -I../../../include '-DPLUGINVERSION="$(PLUGINVERSION)"'

all: sxplugin.so

sxplugin.so: sxplugin.o
	$(LD) -o sxplugin.so -shared sxplugin.o

install: all
	$(INSTALL) -d -m 755 $(LIBDIR)
	$(INSTALL) -s -c -m 4550 sxplugin.so $(LIBDIR)

sxplugin.o: sxplugin.c
	$(CC) $(CFLAGS) -c -o $@ -fPIC $^

clean:
	rm -f *.o *.so *.a

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ -fPIC $^
