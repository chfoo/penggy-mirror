INCLUDES = -I$(srcdir)/include -I..

noinst_LIBRARIES = lib.a

if NEED_GETOPT

getopt_sources = getopt.c getopt1.c

else !NEED_GETOPT

getopt_extra = getopt.c getopt1.c

endif !NEED_GETOPT

EXTRA_DIST = getopt.h gettext.h $(getopt_extra)

lib_a_SOURCES = $(getopt_sources) dummy.c
