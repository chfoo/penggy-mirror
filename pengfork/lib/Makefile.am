INCLUDES = -I$(srcdir)/include -I..

noinst_LIBRARIES = lib.a

if NEED_GETOPT

getopt = getopt.h getopt.c getopt1.c

else !NEED_GETOPT

EXTRA_DIST = getopt.h getopt.c getopt1.c

endif !NEED_GETOPT


lib_a_SOURCES = $(getopt) dummy.c
